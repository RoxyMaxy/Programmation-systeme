//Mandefa SIGTERM any am PID alefa argument

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char **argv) 
{
    if (argc != 2) 
  	{ 
	  	printf("Usage: %s pid\n", argv[0]); 
	  	return 1; 
	  }
    char rep;
    printf("Tuer le processus %s ? (o/n) : ", argv[1]);
    rep = getchar();
    if (rep == 'o') 
	  {
		  kill(atoi(argv[1]), SIGTERM);
	  }
    return 0;
}
