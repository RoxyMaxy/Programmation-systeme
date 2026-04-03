#include <stdio.h>

int main() 
{
    char s[50];
    float x;
    printf("Entrez un réel : ");
    scanf("%s", s);
    sscanf(s, "%f", &x);
    /*Float fotsiny no vakiany; fa tsy maintsy asiana fonction d'entrée eo (ohatra oe scanf)
     satria sscanf mamaky avy am variables, fa tsy avy am entrées*/
    printf("Valeur : %f\n", x);
    return 0;
}
