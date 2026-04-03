#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) 
{
    if (argc != 3) 
  	{ 
	  	printf("Usage: %s a b\n", argv[0]); 
		  return 1; 
	  }
    printf("%d + %d = %d\n", atoi(argv[1]), atoi(argv[2]), atoi(argv[1]) + atoi(argv[2]));
    return 0;
}
