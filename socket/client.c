#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include <strings.h>
#include <sys/stat.h>
#include <fcntl.h>

int create_tcp_client(char* hostip)
{
    int sockfd = 0;
    int flags = 0;
    int re = 0;
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
void client_epoll_wait(int epfd, int sockfd)
{
    int i = 0;
    int sockfd = 0;
    int rcvlen = 0;
    struct epoll_event events[10];
    unsigned char tmp[1024];
    unsigned char buf[1500];
    unsigned char *pbuf = NULL;

    int nfds = epoll_wait(epfd, events, 10, 0);

    for(i = 0; i < nfds; i++ )
    {
        if( events[i].events & EPOLLIN )
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

            printf("%s\n", buf);
        }
    }

    if ((fd = open("./data.txt", O_RDONLY, 0)) == -1)
    {
        perror("open file %s error", "data.txt");
        close(sockfd);
        return;
    }

    if ((len = read(fd, buf, sizeof(buf))) <= 0 )
    {
        perror("read file error");
        close(sockfd);
        close(fd);
        return;
    }

    if (send(sockfd, buf, len, 0) < 0)
    {
        perror("send error");
        close(sockfd);
        close(fd);
        return;
    }

    close(sockfd);
    close(fd);
}
int main()
{
    int fd = create_udp_client("127.0.0.1");
    send_udp_data(fd);
    return 0;
}
