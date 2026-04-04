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
        	// Ouvrir le fichier et chercher le mot
        	FILE *file = fopen("fichier.txt", "r");
        	if (file != NULL) 
			{
	            char line[256];
            	while (fgets(line, sizeof(line), file) != NULL) 
				{
	                if (strstr(line, mot) != NULL) 
					{
                    	found = 1;
                    	break;
                	}
            	}
            	fclose(file);
        	}
        
	        write(tube[1], &found, sizeof(int));
	        found = 1;
	        write(tube[1], &found, sizeof(int));
	        wait(NULL);
	        close(tube[1]);
	}
    return 0;
}
