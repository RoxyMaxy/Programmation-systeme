#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int num_fils = 0;

int main() 
{
    int i;
    pid_t pid;
    for (i = 1; i <= 5; i++) 
	  {
        	num_fils = i;
	        pid = fork();
	        if (pid == 0) 
		      {
	            printf("Processus fils %d\n", num_fils);
	            return 0;
	        }
	  }
    printf("Processus père\n");
    return 0;
}
