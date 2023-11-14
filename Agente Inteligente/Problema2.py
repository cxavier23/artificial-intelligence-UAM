#simula una jornada de limpieza de salones utilizando una Roomba virtual que se mueve de manera aleatoria entre los salones, los limpia y tiene en cuenta la posibilidad de que los salones se ensucien nuevamente. Luego, se calcula la eficiencia de limpieza en función de cuántos salones se mantuvieron limpios al final de la jornada.
#author: Christopher Xavier Sanchez Duran
#UAMC
import os
from numpy import random as rn

class Salon:
	def __init__(self, estado, ubicacion):
		self.estado = estado
		self.ubicacion = ubicacion

	def ensuciar(self,p):
		if rn.uniform(0,1) < p:
			self.estado = "sucio"
		return

class Roomba:
	def __init__(self, salon):
		self.salon = salon
	
	def limpiar(self):
		if self.salon.estado == "sucio":
			self.salon.estado = "limpio"
			print("El salon", self.salon.ubicacion+1, "ha sido limpiado.")
		else:
			print("El salon", self.salon.ubicacion+1, "ya estaba limpio.")
		return

	def mover(self, salones):
		n = len(salones)
		r = rn.randint(1,n-1)
		self.salon = salones[(self.salon.ubicacion + r) % n]
		return

def jornada(salones, p):
	n = len(salones)
	R = Roomba(salones[rn.randint(0,n)])

	for i in range(2*n):
		R.limpiar()
		R.mover(salones)
		for s in salones:
			s.ensuciar(p)

	k = 0
	print("\n\n")
	for i in range(n):
		if salones[i].estado == "limpio":
			k += 1
		print("Salon", i+1, ":", salones[i].estado)
	print("\nEficiencia =", k/n)
	
	return

n = 1000
salones = [Salon("sucio", i) for i in range(n)]
p = 1/n**2
jornada(salones, p)
	
'''
author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/
'''		
