#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() 
{
    int tube[2];
    pipe(tube);
    pid_t pid = fork();
    if (pid == 0) 
	{
	        // fils maka anle mot d miandry
        	char mot[100];
	        int result;
	        close(tube[1]);
	        printf("Mot à chercher : ");
	        scanf("%s", mot);
	        // alefny any amle père le izy
	        read(tube[0], &result, sizeof(int));
	        printf("Mot %s dans le fichier : %s\n", mot, result ? "trouvé" : "non trouvé");
	        close(tube[0]);
	} 
	else 
	{
        	close(tube[0]);
	        int found = 0;
	        found = 1;
	        write(tube[1], &found, sizeof(int));
	        wait(NULL);
	        close(tube[1]);
	}
    return 0;
}
