#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
    pid_t pid = fork(); //duplication fotsiny no ataon'ilay fork
    if (pid == -1) 
	{
		perror("fork"); 
		exit(1); 
	}
    if (pid == 0)
        {
		printf("Processus fils: PID=%d\n", getpid());
	}
    else
	{
        	printf("Processus père: PID=%d\n", getpid());
	}
    return 0;
}
