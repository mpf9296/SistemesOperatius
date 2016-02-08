#Copiar el fitxer desde la linia A a la linea B
def main():
	fitxer=open("ficheroPrueba.txt")
	num_lines = sum(1 for line in fitxer)
	print "Rang (0, ", num_lines-1, ")"
	liniaA=input("Linia amb la que vols comencar a copiar ")
	liniaB=input("fins quina linia vols copiar ")

	if liniaA<liniaB:

		fitxer=open("ficheroPrueba.txt")
		fitxerCopia=open("ficheroCop.txt","w")
		for i,linea in enumerate(fitxer):
			if liniaA <= i and liniaB >= i:
				fitxerCopia.write(linea)

		fitxer.close()
		fitxerCopia.close()
	else :
		print "has posat malament les linies"

main()