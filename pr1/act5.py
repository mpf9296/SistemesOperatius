#Demanar nom fitxer origen i fitxer desti

def main():
	fitxerOrigen=raw_input("Digam el fitxer origen ")
	fitxerDesti=raw_input("Digam el fitxer desti ")

	fitxer=open(fitxerOrigen+".txt")
	fitxerCopia=open(fitxerDesti+".txt","w")
	for linea in fitxer:
		fitxerCopia.write(linea)
	fitxer.close()
	fitxerCopia.close()

main()