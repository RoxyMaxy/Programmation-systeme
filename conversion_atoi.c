#include <stdio.h>
#include <stdlib.h>

int main() 
{
    char s[50];
    printf("Entrez un nombre entier : ");
    scanf("%s", s);
    printf("Valeur : %d\n", atoi(s)); //atoi convertit chaîne de caractères en entiers fotsiny
    return 0;
}
