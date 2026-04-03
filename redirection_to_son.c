#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() 
{
    int tube[2];
    pipe(tube);
    pid_t pid = fork();
    if (pid == 0) 
	{
	        close(tube[1]);
	        dup2(tube[0], STDIN_FILENO);
        	char buf[256];
	        fgets(buf, 256, stdin);
	        printf("Fils lit : %s", buf);
	        close(tube[0]);
	}
	else 
	{
        	close(tube[0]);
	        dup2(tube[1], STDOUT_FILENO);
	        printf("Message du père\n");
	        fflush(stdout);
	        close(tube[1]);
	        wait(NULL);
	}
    return 0;
}
