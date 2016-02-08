//Demanar els noms del fitxer d'entrada i sortida per teclat
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char nomArxiu[80];
	char nomArxiuNou[80];
	int bytesLeidos;
	unsigned char buffer[100];//100 bytes

	printf("Digam el nom del fitxer que vols copiar\n");

	scanf("%79s",nomArxiu);
	strcat(nomArxiu,".txt");
	FILE *f;
	f= fopen(nomArxiu, "r");

	printf("Digam el nom del fitxer al qual vols copiar la informació\n");

	scanf("%79s",nomArxiuNou);
	strcat(nomArxiuNou,".txt");

	FILE *fN;
	fN = fopen(nomArxiuNou,"w");

	//*******************
	if(f == NULL){
		printf("No s'ha pogut obrir el fitxer\n");
		exit(1);
	}
	if (fN == NULL)
	{
		printf("No s'ha pogut crear el fitxer\n");
		exit(1);
	}
	//********************

	bytesLeidos = fread(buffer, sizeof(char), sizeof(buffer), f);
	while(bytesLeidos!= 0) {
		fwrite(buffer, sizeof(char), bytesLeidos, fN);
		bytesLeidos = fread(buffer, sizeof(char), sizeof(buffer), f);
	}

	fclose(f);
	fclose(fN);

	return 0;
}