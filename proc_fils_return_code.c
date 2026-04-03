#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() 
{
    int status;
    pid_t pid = fork();
    if (pid == 0) 
  	{ 
	  	exit(42); 
	  }
    waitpid(pid, &status, 0);
    printf("Code de sortie du processeur fils : %d\n", WEXITSTATUS(status));
    return 0;
}
