#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() 
{
    char *nom = "/tmp/monfifo";
    mkfifo(nom, 0644);
    int fd = open(nom, O_WRONLY);
    FILE *fp = fdopen(fd, "w");
    fprintf(fp, "coucou\n");
    fclose(fp);
    unlink(nom);
    return 0;
}
