#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() 
{
    pid_t pid1, pid2;
    int d1, d2;
    time_t t1 = time(NULL);
    srand(time(NULL));
    d1 = rand() % 10 + 1;
    d2 = rand() % 10 + 1;

    pid1 = fork();
    if (pid1 == 0) 
    { 
      printf("fils 1 attend %d sec\n", d1); 
      sleep(d1); 
      return 0; 
    }

    pid2 = fork();
    if (pid2 == 0) 
    { 
      printf("fils 2 attend %d sec\n", d2); 
      sleep(d2); 
      return 0; 
    }

    wait(NULL); //Mforcer anle processus père hiandry anle fils
    wait(NULL);
    printf("Durée totale : %ld sec\n", time(NULL) - t1);
    return 0;
}
