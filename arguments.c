#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) 
{
    int i;
    printf("Nombre d'arguments : %d\n", argc - 1);
    for (i = 1; i < argc; i++)
    {
        printf("argv[%d] = %s (longueur=%lu)\n", i, argv[i], strlen(argv[i]));
    }
    return 0;
}
