//Demanar els noms del fitxer d'entrada i sortida per teclat
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(){

	char nomArxiu[80];
	char nomArxiuNou[80];
	int bytesLeidos;
	char buffer[100];//100 bytes

	printf("Digam el nom del fitxer que vols copiar\n");

	scanf("%79s",&nomArxiu);
	strcat(nomArxiu,".txt");
	int f;
	f = open("fichero.txt",O_RDONLY);

	printf("Digam el nom del fitxer al qual vols copiar la informació\n");

	scanf("%79s",&nomArxiuNou);
	strcat(nomArxiuNou,".txt");

	int fN;
	fN = open(nomArxiuNou,O_WRONLY | O_CREAT | O_TRUNC, 0700);

	bytesLeidos = read(f, &buffer, sizeof(char));
	while(bytesLeidos!= 0) {
		write(fN, &buffer, bytesLeidos);
		bytesLeidos = read(f, &buffer, sizeof(char));
	}

	close(f);
	close(fN);

	return 0;
}