#include <stdio.h>
#include <fcntl.h>

int main() 
{
    char *nom = "/tmp/monfifo";
    int fd = open(nom, O_RDONLY);
    FILE *fp = fdopen(fd, "r");
    char s[50];
    fscanf(fp, "%s", s);
    printf("Reçu : %s\n", s);
    fclose(fp);
    return 0;
}
