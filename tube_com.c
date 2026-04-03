//ampiresahana am tube ny fils sy père
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define BUFSIZE 256

int main() 
{
    int tube[2];
    char message[BUFSIZE], bufR[BUFSIZE];
    pipe(tube);
    pid_t pid = fork();
    if (pid == 0) 
	{
        	close(tube[1]);
	        read(tube[0], bufR, BUFSIZE);
	        printf("Fils reçu : %s\n", bufR);
	        close(tube[0]);
    	} 
	else 
	{
	        close(tube[0]);
	        sprintf(message, "Bonjour fils depuis le père (PID=%d)", getpid());
	        write(tube[1], message, BUFSIZE);
	        wait(NULL);
	        close(tube[1]);
	}
    return 0;
}
