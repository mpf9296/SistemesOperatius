#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


int main() 
{
    int a, b[2], b2[2], nbytes;
    char string [100], buffer [100], buffer2[100], entrada[100];

    pid_t pid; 
    char fin[5] = "FINAL";
    
    

    pipe(b);
    pipe(b2);
    
    if((pid = fork()) == -1) {
        perror("error en el fork");
        exit(1);
    }

    if(pid != 0){
        printf ("Introdueix el nom del fitxer d'escritura:\n");  
        scanf("%s",entrada);
        write(b2[1],entrada, sizeof(entrada));

        printf("Escriu un text:\n");
        fgets(string, sizeof(string), stdin);
        
        while (strncmp(string,fin,5) != 0) {
            write(b[1], &string, strlen(string)); 
            fgets(string, 100, stdin);
        }

    }
    else {
        nbytes = read(b2[0], &buffer2, sizeof(buffer2));
        a = open(buffer2, O_WRONLY|O_CREAT|O_TRUNC, 0644);
        do {
            nbytes = read(b[0], &buffer, sizeof(buffer));
            write(a, &buffer, nbytes);
        } while (strncmp(buffer,fin,5) != 0); 
    }

    close(a);
    return 0;
    exit(0);
}

/*
void err_sys(const char* cadena){ 
    perror(cadena); 
    exit(1);
} 

int main () {

    int a, can[2], can2[2];
    char buffer [100], entrada [80], string[100];
    char buffer2[100];
    pid_t pid; 
    char fin[5] = "FINAL";
    int nbytes;
    int nomLlegit=1;

    pipe(can);
    pipe(can2);

    if((pid = fork()) == -1) {
        perror("error en el fork");
        exit(1);
    }

    if(pid != 0) {
        close(can[0]);
        if (nomLlegit == 1) {
            printf ("Introdueix el nom del fitxer d'escritura:\n(No cal format)\n");  
            scanf("%s", entrada);
            strcat(entrada,".txt");
            write(can[1],entrada, sizeof(entrada));
            nomLlegit = 2;
        }
        close(can[1]);

        if (nomLlegit == 2) {
            printf("Escriu un text:\n");
            fgets(string, sizeof(string), stdin);
            close(can2[0]);
            while (strncmp(string,fin,5) != 0) {
                write(can2[1], &string, strlen(string)); 
                fgets(string, 100, stdin);
            }
            close(can2[1]);
        }

    } 
    else {
        close(can[1]);
        if (nomLlegit == 1) {
            read(can[0],buffer, sizeof(buffer));
            a = open(buffer, O_WRONLY|O_CREAT|O_TRUNC, 0644);
            nomLlegit = 2;
        }
        close(can[0]);

        close(can2[1]);
        if (nomLlegit == 2) {
            do {
                nbytes = read(can2[0], &buffer2, sizeof(buffer2));
                write(a, &buffer2, nbytes);
            } while (strncmp(buffer2,fin,5) != 0); 
        }
        close(can2[0]);
    }

    waitpid(pid, NULL, 0 );
    return 0;
    exit (0);
}
*/