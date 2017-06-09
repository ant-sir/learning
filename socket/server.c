#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct _PKT_INFO
{
    int protocol;
    int ifid;
    int srcslot;
    int olt;
    int pktdir;
} PKT_INFO;

typedef union _PKT_INFO_SEND
{
    PKT_INFO info;
    unsigned char buf[sizeof(PKT_INFO)];
} PKT_INFO_SEND;

int create_tcp_server(void)
{
    int sockfd = 0;
    int flags = 0;
    struct sockaddr_in addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Create socket error");
        return -1;
    }
    
    flags = fcntl(sockfd, F_GETFL, 0);

    if (fcntl(sockfd, F_SETFL, flags|O_NONBLOCK) < 0)
    {
        perror("set fcntl error");
        return -1;
    }

    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(8000);

    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == -1)
    {
        perror("bind error");
        return -1;
    }

    if (listen(sockfd, 10) == -1)
    {
        perror("listen error");
        return -1;
    }

    return sockfd;
}

int create_epoll_handle(int sockfd)
{
    int epfd = 0;
    struct epoll_event ev;

    if ((epfd = epoll_create(10)) == -1)
    {
        perror("epoll create error");
        return -1;
    }

    ev.data.fd = sockfd;
    ev.events = EPOLLIN | EPOLLOUT | EPOLLET;

    if (epoll_ctl(epfd, EPOLL_CTL_ADD, sockfd, &ev) < 0)
    {
        perror("epoll ctl error");
        return -1;
    }

    return epfd;
}

void server_epoll_wait(int epfd, int listenfd)
{
    int i = 0;
    int sockfd = 0;
    int rcvlen = 0;
    int clilen = 0;
    unsigned char *pbuf = NULL;
    struct sockaddr_in clientaddr;
    struct epoll_event ev;
    struct epoll_event events[10];
    unsigned char tmp[1024];
    unsigned char buf[1500];

    int nfds = epoll_wait(epfd, events, 10, 0);
    
    for(i = 0; i < nfds; i++ )
    {
        if (events[i].data.fd == listenfd)
        {
            if ((sockfd = accept(listenfd, (struct sockaddr *)&clientaddr, &clilen)) < 0)
            {
                perror("accept error");
                return;
            }
            else
            {
                printf("accept a new connect. ip is %s\n", inet_ntoa(clientaddr.sin_addr));
                bzero(&ev, sizeof(ev));
                ev.data.fd = sockfd;
                ev.events = EPOLLIN | EPOLLOUT | EPOLLET;

                if (epoll_ctl(epfd, EPOLL_CTL_ADD, sockfd, &ev) < 0)
                {
                    perror("epoll ctl error");
                    return;
                }

            }
        }
        else if( events[i].events & EPOLLIN )
        {
            sockfd = events[i].data.fd;
            bzero(tmp, sizeof(tmp));
            bzero(buf, sizeof(buf));
            pbuf = buf;
            while((rcvlen = recv(sockfd, tmp, sizeof(tmp), 0)) > 0)
            {
                memmove(pbuf, tmp, rcvlen);
                pbuf += rcvlen;
            }

            rcvlen = pbuf - buf;

            for(i = 0; i < rcvlen; i++)
                printf("%02x ", buf[i]);
            printf("\n");
        }
    }
}

int main()
{
    int sockfd = create_tcp_server();
    int epfd = create_epoll_handle(sockfd);

    while(1)
    {
       server_epoll_wait(epfd, sockfd);
       sleep(1);
    }

    return 0;
}
