#Fer un primer script per tal de llegir un fitxer i copiarlo

def main():
	fitxer=open("ficheroPrueba.txt")
	fitxerCopia=open("ficheroNuevo.txt","w")
	for linea in fitxer:
		fitxerCopia.write(linea)
	fitxer.close()
	fitxerCopia.close()

main()

