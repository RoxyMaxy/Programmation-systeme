#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>

int *tab;
int n;
sigjmp_buf env;

void gestionnaire(int sig) 
{
    if (sig == SIGSEGV) 
	  {
        	printf("\nErreur de segmentation ! Resaisir l'indice.\n");
	        siglongjmp(env, 1);
	  }
}

int main() 
{
    struct sigaction sa;
    sa.sa_handler = gestionnaire;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGSEGV, &sa, NULL);
    printf("Taille du tableau : ");
    scanf("%d", &n);
    tab = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) 
  	{
  		tab[i] = i * 10;
  	}
    int idx;
    sigsetjmp(env, 1);
    printf("Indice à afficher (0 à %d) : ", n - 1);
    scanf("%d", &idx);
    printf("tab[%d] = %d\n", idx, tab[idx]);
    free(tab);
    return 0;
}
