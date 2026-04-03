#include <stdio.h>

void affiche(int n) 
{ 
	printf("n = %d\n", n); 
}

int saisit(void) 
{ 
	int n; scanf("%d", &n); 
	return n; 
}

int main() 
{
    void (*fAffiche)(int) = affiche;
    int (*fSaisit)(void) = saisit;
    int val = fSaisit();
    fAffiche(val);
    return 0;
}
