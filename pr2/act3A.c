//Fer un programa que llegeixi i copii un fitxer en blocs de 100 bytes
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){

	int f;
	int fN;
	int bytesLeidos;
	unsigned char buffer[100];//100 bytes

	f = open("fichero.txt",O_RDONLY);
	fN = open("ficheroNuevo.txt",O_WRONLY);


	bytesLeidos = read(f, &buffer, sizeof(char));
	while(bytesLeidos!= 0) {
		write(fN, &buffer, bytesLeidos);
		bytesLeidos = read(f, &buffer, sizeof(char));
	}
	
	close(f);
	close(fN);

return 0;
}