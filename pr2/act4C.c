//Fer la lectura/escriptura caràcter a caràcter
#include <stdio.h>
#include <stdlib.h>

int main(){

	FILE *f;
	FILE *fN;
	int bytesLeidos;
	unsigned char buffer[1];//100 bytes

	f = fopen("fichero.txt","r");
	fN = fopen("ficheroNuevo.txt","w");

	if(f==NULL){
		printf("No s'ha pogut obrir el fitxer\n");
		exit(1);
	}
	if (fN == NULL)
	{
		printf("No s'ha pogut crear el fitxer\n");
		exit(1);
	}

	bytesLeidos = fread(buffer, sizeof(char), sizeof(buffer), f);
	while(bytesLeidos!= 0) {
		fwrite(buffer, sizeof(char), bytesLeidos, fN);
		bytesLeidos = fread(buffer, sizeof(char), sizeof(buffer), f);
	}


	fclose(f);
	fclose(fN);
	return 0;
}