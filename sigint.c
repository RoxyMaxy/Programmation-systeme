#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int donnees[5];

void gestionnaire(int sig) 
{
    if (sig == SIGINT) 
  	{
        	FILE *f = fopen("/tmp/sauve.txt", "w");
	        for (int i = 0; i < 5; i++) 
	      	{
			        fprintf(f, "%d ", donnees[i]);
		      }
	        fclose(f);
	        printf("\nSauvegarde OK. Fin.\n");
	        exit(0);
	  }
}

int main() 
{
    struct sigaction sa;
    sa.sa_handler = gestionnaire;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);
    for (int i = 0; i < 5; i++) 
  	{ 
	  	printf("donnees[%d] = ", i); 
	  	scanf("%d", &donnees[i]); 
	  }
    while (1) 
	  { 
	  	sleep(1); 
	  }
    return 0;
}
