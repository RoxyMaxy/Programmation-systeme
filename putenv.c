#include <stdio.h>
#include <stdlib.h>

int main() 
{
    char buf[200];
    char *path = getenv("PATH");
    char *home = getenv("HOME");
    sprintf(buf, "PATH=%s:%s/bin", path, home); //otran oe "path no PATH taloha, d home no tiana hanovàna azy"
    putenv(buf); //Eto izy manao confirmation an'ilay fanovàna fotsiny
    printf("Nouveau PATH : %s\n", getenv("PATH"));
    return 0;
}
