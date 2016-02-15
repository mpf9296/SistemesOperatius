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

    int a, can[2], can2[2];
    char buffer [100], entrada [80];
    pid_t pid; 

    

    pipe(can);
    pipe(can2);

    if((pid = fork()) == -1) {
        perror("error en el fork");
        exit(1);
    }

    if((pid = fork()) != 0) {
        close(can[0]);
        printf ("Introdueix el nom del fitxer d'escritura:\n(No cal format)\n");  
        scanf("%s", entrada);
        strcat(entrada,".txt");
        write(can[1],entrada, sizeof(entrada));
        close(can[1]);
    } 
    else {
        close(can[1]);
        read(can[0],buffer, sizeof(buffer));
        if (access(buffer) != -1) {
            a = open(buffer, O_RDONLY, 0644);
            close(can[0]);
        }
        
    }

    waitpid(pid, NULL, 0 );
    return 0;
    exit (0);
}