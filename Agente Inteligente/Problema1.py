#El código simula la interacción de un agente con una máquina expendedora, le permite ver su balance, insertar monedas, comprar productos y devolver dinero si es necesario. El agente puede interactuar con la máquina hasta que elija salir.
import os

#author: Christopher Xavier Sanchez Duran
#UAMC
def AGENTE_INTELIGENTE():
	balance = 0
	
	while True:
		print("Balance = ", balance, "\n\n")
		
		print("A1) Chela - $20")
		print("A2) Refresco - $10")
		print("A3) Juguito de Maldad - $14 \n")
	
		print("M ) Insertar Moneda")
		print("D ) Devolver Dinero")
		print("S ) Salir\n\n")
		
		PERCEPCION = input()
		print("\n")
		
		if PERCEPCION == "M": 
			moneda = int(input("\nValor de moneda: "))
			balance += moneda*(moneda>0)
			print("Balance = ", balance)
		elif PERCEPCION == "D":
			print("Toma tus", balance, "pesos :(")
			balance = 0
		elif PERCEPCION == "A1":
			if balance > 20:
				print("Toma tu chela :D")
				balance -= 20
				print("Balance = ", balance)
			else:
				print("Balance Insuficiente")
		elif PERCEPCION == "A2":
			if balance > 10:
				print("Toma tu chesco :)")
				balance -= 10
				print("Balance = ", balance)
			else:
				print("Balance Insuficiente")
		elif PERCEPCION == "A3":
			if balance > 14:
				print("Toma tu juguito de maldad >:D")
				balance -= 14
				print("Balance = ", balance)
			else:
				print("Balance Insuficiente")
		else:
			os.system("cls||clear")
			print("Toma tus", balance, "pesos :(")
			print("Adios :D")
			break;
			
		input("Presiona enter para continuar...")
		os.system("cls||clear")

	return 

AGENTE_INTELIGENTE()
'''
author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/
'''