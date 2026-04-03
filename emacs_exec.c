#include <stdio.h>
#include <unistd.h>

int main() 
{
    char fichier[100];
    printf("Nom du fichier : ");
    scanf("%s", fichier);
    char *args[] = {"emacs", fichier, NULL};
    execv("/usr/bin/emacs", args);//asaina msoty anaty emacs le fichier
    perror("execv");
    return 1;
}
