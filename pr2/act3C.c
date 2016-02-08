//Demanar la mida del bloc de lectura/escriptura
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char *argv[]){

	int f,fN;
	int bytesLeidos;
	int mida;
	printf("Digues la mida del buffer:");
	scanf("%d", &mida);
	unsigned char buffer[mida];

	f = open("fichero.txt",O_RDONLY);
	fN = open("ficheroNuevo.txt",O_WRONLY);


	bytesLeidos = read(f, &buffer, sizeof(char));
	while(bytesLeidos > 0) {
		write(fN, &buffer, bytesLeidos);
		bytesLeidos = read(f, &buffer, sizeof(char));	
	}

	close(f);
	close(fN);
	
	return 0;
}