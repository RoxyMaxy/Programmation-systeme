
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define PORT 12345
#define BUFSIZE 256

int main() 
{
    int srv, cli;
    struct sockaddr_in adr;
    socklen_t len = sizeof(adr);
    char buf[BUFSIZE];

    srv = socket(AF_INET, SOCK_STREAM, 0);
    memset(&adr, 0, sizeof(adr));
    adr.sin_family = AF_INET;
    adr.sin_port = htons(PORT);
    adr.sin_addr.s_addr = INADDR_ANY;
    bind(srv, (struct sockaddr*)&adr, sizeof(adr));
    listen(srv, 5);
    printf("Serveur en écoute sur port %d\n", PORT);
    cli = accept(srv, (struct sockaddr*)&adr, &len);
    read(cli, buf, BUFSIZE);
    printf("Reçu : %s\n", buf);
    write(cli, "OK\n", 3);
    close(cli);
    close(srv);
    return 0;
}
