#include <stdio.h>

extern char **environ; //extern midika oe efa misy variable "environ" any ho aany, ao am système, d iny no ampiasaina

int main() 
{
    int i;
    for (i = 0; environ[i] != NULL; i++)
    {
        printf("%s\n", environ[i]); //
    }
    return 0;
}
