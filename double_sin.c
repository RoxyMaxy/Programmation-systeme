//Mandefa double (sin(x)) par tube

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <sys/wait.h>

int main() 
{
    int tube[2];
    double x, val;
    pipe(tube);
    pid_t pid = fork();
    if (pid == 0) 
	  {
     	close(tube[1]);
	    read(tube[0], &val, sizeof(double));
	    printf("Fils reçu sin(x) = %.4f\n", val);
	    close(tube[0]);
	  }
	  else 
	  {
      close(tube[0]);
	    printf("Entrez x : ");
	    scanf("%lf", &x);
	    val = sin(x);
	    write(tube[1], &val, sizeof(double));
	    wait(NULL);
	    close(tube[1]);
	  }
    return 0;
}
