#include <stdio.h>
#include <errno.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <string.h>
int socket_set_fcntl(int sockfd, int flags)
{
    int old_flags = 0;
    
    if ((old_flags = fcntl(sockfd, F_GETFL, 0)) < 0)
    {
        perror("get fcntl error");
        return -1;

    }

    if (fcntl(sockfd, F_SETFL, old_flags | flags) < 0)
    {
        perror("set fcntl error");
        return -1;
    }

    return 0;
}
int create_tcp_client(char* hostip)
{
    int sockfd = 0;
    int re = 0;
    struct sockaddr_in addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Create socket error");
        return -1;
    }

    if (socket_set_fcntl(sockfd, O_NONBLOCK) < 0)
        return -1;

    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(hostip);
    addr.sin_port = htons(8000);

    if ((re = connect(sockfd, (struct sockaddr*)&addr, sizeof(addr))) == -1)
    {
        if (errno != EINPROGRESS)
        {
            perror("connect error");
            return -1;
        }
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
int client_epoll_wait(int epfd)
{
    int i = 0;
    int sockfd = 0;
    int rcvlen = 0;
    int optval = 0;
    int optlen = 0;
    struct epoll_event events[10];
    unsigned char tmp[1024];
    unsigned char buf[1500];
    unsigned char *pbuf = NULL;

    int nfds = epoll_wait(epfd, events, 10, 0);

    for(i = 0; i < nfds; i++)
    {
        if(events[i].events & EPOLLIN)
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
            if (rcvlen == -1)
            {
                if (errno != EAGAIN && errno != EWOULDBLOCK)
                {
                    perror("recv error");
                    close(sockfd);
                    return -1;
                }
            }
            else if (rcvlen == 0)
            {
                perror("server error");
                close(sockfd);
                return -1;
            }
            
            if ((rcvlen = pbuf - buf) > 0)
            {
                printf("%s\n", buf);
            }
        }
        else if(events[i].events & EPOLLOUT)
        {
            sockfd = events[i].data.fd;
            if (getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &optval, &optlen) < 0)
            {
                perror("getsockopt error");
                return -1;
            }
            if (optval == 0)
                printf("connect success.\n");
            else
            {
                printf("connect failed.\n");
                return -1;
            }
        }
    }

    return 0;
}

int main()
{
    int count = 0;
    int fd = create_tcp_client("127.0.0.1");
    int epfd = create_epoll_handle(fd);
    char buf[128] = {0};

    while(1)
    {
        bzero(buf, sizeof(buf));
        client_epoll_wait(epfd);
        sleep(1);
        sprintf(buf, "I send the count %d to you.", count++);
        if (send(fd, buf, strlen(buf), 0) < 0)
        {
            perror("send error");
            close(fd);
            close(epfd);
            return -1;
        }
        printf("send data to server.");

    }
    sleep(3);
    close(fd);
    close(epfd);

    
    return 0;
}
