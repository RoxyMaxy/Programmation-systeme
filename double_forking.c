#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() 
{
    pid_t pid1, pid2;
    pid1 = fork();
    if (pid1 == 0) 
	{ 
		printf("Processus fils 1\n"); 
		return 0; 
	}
    pid2 = fork();
    if (pid2 == 0) 
	{ 
		printf("Processus fils 2\n"); 
		return 0; 
	}
    printf("Processus père\n");
    return 0;
}
