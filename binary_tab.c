//Manao tableau d tazonina binaire iny

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() 
{
    int n, tab[100];
    printf("Combien d'entiers ? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
	  { 
		  printf("tab[%d] = ", i); 
		  scanf("%d", &tab[i]); 
	  }
    int fd = open("tableau.bin", O_WRONLY | O_CREAT | O_TRUNC, 0640);
    write(fd, tab, n * sizeof(int));
    close(fd);
    printf("Sauvegardé.\n");
    return 0;
}
