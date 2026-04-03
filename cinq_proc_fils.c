#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
    int i;
    pid_t pid;
    for (i = 0; i < 5; i++) 
  	{
     	  pid = fork();
  	    if (pid == 0) 
		  {
	      printf("Processus fils %d (PID=%d)\n", i+1, getpid());
  	    break;
	    }
	  }
    if (pid != 0) 
	  {
		  printf("Processus père\n");
	  }
    return 0;
}
