#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() 
{
    int tab[100], n = 0, val;
    int fd = open("tableau.bin", O_RDONLY);
    while (read(fd, &val, sizeof(int)) == sizeof(int))
  	{
        	tab[n++] = val;
	  }
    close(fd);
    printf("Lu %d entiers : ", n);
    for (int i = 0; i < n; i++) 
	  {
		  printf("%d ", tab[i]);
	  }
    printf("\n");
    return 0;
}
