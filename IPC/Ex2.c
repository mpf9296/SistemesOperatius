#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main() 
{
    int a;
    char string [100], buffer [100], entrada [80];
	pid_t pid; 
	char b[] = {"hi1","hi2"};
	

	

    pipe(b);
    
    if((pid = fork()) == -1) {
        perror("error en el fork");
        exit(1);
    }

    if(pid == 0){
    	close(b[0]);
		printf ("Nom del fitxer d'escritura: (sense format)\n");
		scanf("%s",entrada);
		strcat(entrada,".txt");
		strcpy(b[1],entrada);
		close(b[1]);
          
    }
    else {
    	close(b[1]);
    	a = open(b[1], O_WRONLY|O_CREAT|O_TRUNC, 0644);
    	close(b[0]);
    }
    waitpid( pid, NULL, 0 );
    close(a);
    return 0;
    exit(0);
}