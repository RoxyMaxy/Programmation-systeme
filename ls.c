//Mliste fichiers anatin'ny répertoire 1

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main(int argc, char **argv) 
{
    if (argc < 2) 
  	{ 
	  	printf("Usage: %s rep\n", argv[0]); 
		  return 1; 
	  }
    DIR *d = opendir(argv[1]);
    if (!d) 
	  {   
		  perror("opendir"); 
	  	return 1; 
	  }
    struct dirent *e;
    while ((e = readdir(d)) != NULL)
    {
		  printf("%s\n", e->d_name);
	  }
    closedir(d);
    return 0;
}
