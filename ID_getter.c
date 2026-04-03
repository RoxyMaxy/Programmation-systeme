#include <stdio.h>
#include <unistd.h>

int main() 
{
    printf("PID = %d\n", getpid());
    printf("UID = %d\n", getuid());
    return 0;
}
