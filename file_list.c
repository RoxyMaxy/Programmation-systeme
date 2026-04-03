//Mlister fichiers latsaky ny 1MO ny taille-ny

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char **argv) 
{
    if (argc < 2) 
  	{ 
	  	printf("Usage: %s rep\n", argv[0]); 
		  return 1; 
	  }
    DIR *d = opendir(argv[1]);
    struct dirent *e;
    struct stat st;
    char path[512];
    while ((e = readdir(d)) != NULL) 
	  {
        	sprintf(path, "%s/%s", argv[1], e->d_name);
	        stat(path, &st);
	        if (S_ISREG(st.st_mode) && st.st_size > 1000000)
	        {
		      	printf("%s (UID=%d, taille=%ld)\n", e->d_name, st.st_uid, st.st_size);
		      }
	}
    closedir(d);
    return 0;
}
