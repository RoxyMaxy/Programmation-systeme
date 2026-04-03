#include <stdio.h>

int main() 
{
    char s[100];
    int a;
	float x;
    printf("Entrez un entier : ");
    scanf("%d", &a);
	printf("Et un réel: ");
	scanf("%f", &x);
    sprintf(s, "Vous avez entré a=%d et x=%f", a, x); //io indray manao conversion de variables en char
    printf("%s\n", s);
    return 0;
}
