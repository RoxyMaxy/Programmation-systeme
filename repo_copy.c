#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) 
{
    if (argc != 2) 	
  	{ 
	  	printf("Usage: %s repertoire\n", argv[0]); return 1; 
	  }
    char cmd[200];
    sprintf(cmd, "cp -r . %s", argv[1]);
    system(cmd);
    return 0;
}
