#include <stdio.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

int main(void)
{
	int sockfd;
	struct sockaddr_in servaddr;
	char buf[1024];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		perror("socket");
		return -1;
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(1234);
	inet_pton(AF_INET, "192.168.1.104", &servaddr.sin_addr);
	if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr) < 0))
	{
		perror("connect");
		return -1;
	}

	strcpy(buf, "hello world");
	write(sockfd, buf, strlen(buf) + 1);

	return 0;
}
