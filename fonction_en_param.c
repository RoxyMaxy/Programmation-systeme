#include <stdio.h>

void affDecimal(int n) 
{ 
	printf("Décimal : %d\n", n); 
}

void affHexa(int n)
{ 
	printf("Hexa    : %x\n", n); 
}

void execAff(void (*f)(int), int n)
{
	f(n);
}

int main() 
{
    execAff(affDecimal, 255);
    execAff(affHexa, 255);
    return 0;
}
