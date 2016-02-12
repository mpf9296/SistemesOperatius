#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

void err_sys(const char* cadena){ 

 perror(cadena); 

 exit(1);
} 

int main () {

    int a, canonada[2], canonada2[2], nbytes;
    int bucle = 1;
    char buffer [200], entrada [80];
    pid_t pid; 

    printf ("Introdueix el nom del fitxer d'escritura:\n(No cal format)\n");  
    scanf("%s", entrada);
    strcat(entrada,".txt");
    a = open(entrada, O_WRONLY|O_CREAT|O_TRUNC, 0644);

    pipe(canonada);
    pipe(canonada2);

    if((pid = fork()) == -1) {
        perror("error en el fork");
        exit(1);
    }

    if((pid = fork()) == 0) {
        close(canonada[1]);
        close(canonada2[0]);

        while ((nbytes=read(canonada[0], buffer, 200))>0) write(1, buffer, nbytes);
        close(canonada[0]);

        strcpy(buffer, "Canonada fill.\n" );
        write(canonada2[1], buffer, strlen(buffer));
        close(canonada2[1]);
    } 
    else {
        close(canonada[0]);
        close(canonada2[1]);

        strcpy(buffer, "Canonada padre\n");
        write(canonada[1], buffer, strlen(buffer));
        close(canonada[1]);

        while((nbytes = read(canonada2[0], buffer, 200) > 0)) write(1, buffer, nbytes);
        close(canonada2[0]);
    }

    waitpid(pid, NULL, 0 );
    return 0;
    exit (0);
}