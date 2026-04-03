// Processus père Mstop na mcontinue na mkill processus fils

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main() 
{
    pid_t pid = fork();
    if (pid == 0) 
  	{
        	while (1) 
      		{ 
			        printf("Processus fils en cours\n"); 
			        sleep(1); 
		      }
  }
  char c;
  while (1) 
	{
        	printf("s=stop r=reprend q=quitter : ");
	        scanf(" %c", &c);
	        if (c == 's') 
	      	{
			      kill(pid, SIGSTOP);
		      }
	        else if (c == 'r') 
		      {
			      kill(pid, SIGCONT);
		      }
	        else if (c == 'q') 
		      { 
			      kill(pid, SIGTERM); 
			      wait(NULL); 
			      break; 
		      }
	}
  return 0;
}
