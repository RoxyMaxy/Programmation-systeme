include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

sem_t sem;

void *thread_fn(void *arg) 
{
    int id = (int)(long)arg;
    sem_wait(&sem);
    printf("Thread %d entre en section critique\n", id);
    sleep(rand() % 3 + 1);
    printf("Thread %d sort de section critique\n", id);
    sem_post(&sem);
    pthread_exit(NULL);
}

int main(int argc, char **argv) 
{
    if (argc != 2) 
  	{ 
  		printf("Usage: %s max\n", argv[0]); 
  		return 1; 
	  }
    srand(time(NULL));
    int max = atoi(argv[1]);
    sem_init(&sem, 0, max);
    pthread_t threads[10];
    for (int i = 0; i < 10; i++)
    {
		pthread_create(&threads[i], NULL, thread_fn, (void*)(long)i);
	  }
    for (int i = 0; i < 10; i++)    
	  {
	  	pthread_join(threads[i], NULL);
	  }
    sem_destroy(&sem);
    return 0;
}
