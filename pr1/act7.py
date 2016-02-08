def main():

	fitxer=open("ficheroPrueba.txt")
	fitxerCopia=open("ficheroNuevo.txt","w")
	prueba = fitxer.readlines()
	count=len(prueba)
	
	while count >=1:
		count = count-1
		fitxerCopia.write(prueba[count])

	fitxer.close()
	fitxerCopia.close()
	

main()