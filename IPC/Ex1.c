#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main() 
{
    int a, b[2], nbytes;
    char string [100], buffer [100], entrada [80];
	pid_t childpid; 
	char fin[100] = "FINAL";
	

	printf ("Nom del fitxer d'escritura: (sense format)");  
	scanf("%s", entrada);
	strcat(entrada,".txt");  
	a = open(entrada, O_WRONLY|O_CREAT|O_TRUNC, 0644);

    pipe(b);
    
    if((childpid = fork()) == -1) {
        perror("error en el fork");
        exit(1);
    }

    if(childpid == 0){
		printf("Escriu un text:");
        scanf("%s", string);
		while (strcmp(string,fin) != 0) {
			write(b[1], &string, strlen(string)); 
			scanf("%s", string);
		}
          
    }
    else {
	  nbytes = read(b[0], &buffer, sizeof(string));
	  write(a, &buffer, nbytes);
    }

    close(a);
    return 0;
    exit(0);
}