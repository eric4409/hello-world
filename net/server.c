#include <stdio.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

int main(void)
{
	int listenfd, connfd;
	struct sockaddr_in servaddr;
	char buf[1024];
	
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(1234);
	bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
	listen(listenfd, 5);
	while(1)
	{
		connfd = accept(listenfd, NULL, NULL);

	}
	return 0;
}
