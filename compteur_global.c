#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int compte = 0;
int limite;
pthread_mutex_t mx = PTHREAD_MUTEX_INITIALIZER;

void *incrementeur(void *arg) 
{
    while (1) 
  	{
        	pthread_mutex_lock(&mx);
	        if (compte >= limite) 
	    		{ 
			    	pthread_mutex_unlock(&mx); 
				    break; 
			    }
	        compte++;
	        pthread_mutex_unlock(&mx);
	        sleep(rand() % 5 + 1);
	  }
    pthread_exit(NULL);
}

void *afficheur(void *arg) 
{
    while (1) 
  	{
	       	sleep(2);
	        pthread_mutex_lock(&mx);
	        printf("Compteur = %d\n", compt);
	        int stop = (compt >= limite);
	        pthread_mutex_unlock(&mx);
	        if (stop) 
	      	{
			      break;
		      }
	}
    pthread_exit(NULL);
}

int main(int argc, char **argv) 
{
    if (argc != 2) 
	  { 
		  printf("Usage: %s limite\n", argv[0]); 
		  return 1; 
  	}
    limite = atoi(argv[1]);
    pthread_t t1, t2;
    pthread_create(&t1, NULL, incrementeur, NULL);
    pthread_create(&t2, NULL, afficheur, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
