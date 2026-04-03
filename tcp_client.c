//Mandefa message any am serveur

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUFSIZE 256

int main(int argc, char **argv) 
{
    if (argc != 3) 
  	{ 
	  	printf("Usage: %s ip port\n", argv[0]); 
	  	return 1; 
	  }
    int sock;
    struct sockaddr_in adr;
    char buf[BUFSIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    memset(&adr, 0, sizeof(adr));
    adr.sin_family = AF_INET;
    adr.sin_port = htons(atoi(argv[2]));
    inet_aton(argv[1], &adr.sin_addr);
    connect(sock, (struct sockaddr*)&adr, sizeof(adr));

    printf("Message : ");
    fgets(buf, BUFSIZE, stdin);
    write(sock, buf, strlen(buf));
    read(sock, buf, BUFSIZE);
    printf("Réponse : %s\n", buf);
    close(sock);
    return 0;
