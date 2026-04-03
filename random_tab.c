#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct 
{ 
	int *tab;
	int n;
} Args;

void *aff_tab(void *arg) 
{
    Args *a = (Args*)arg;
    for (int i = 0; i < a->n; i++) 
  	{
	  	printf("%d ", a->tab[i]);
	  }
    printf("\n");
    pthread_exit(NULL);
}

int main() 
{
    int tab[] = {1, 2, 3, 4, 5};
    Args a = {tab, 5};
    pthread_t t;
    pthread_create(&t, NULL, aff_tab, &a);
    pthread_join(t, NULL);
    return 0;
}
