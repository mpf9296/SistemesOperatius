#Copiar fitxer pero girant linies de text

def invertir(linea):
		return linea[::-1]

def main():

	fitxer=open("ficheroPrueba.txt")
	fitxerCopia=open("ficheroNuevo.txt","w")

	for linea in fitxer:
		fitxerCopia.write(invertir(linea))
	fitxer.close()
	fitxerCopia.close()
	

main()