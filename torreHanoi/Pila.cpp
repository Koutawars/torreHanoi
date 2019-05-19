#include "pch.h"
#include "Pila.h"
#include <iostream>


Pila::Pila()
{
	this->lista = std::vector<int>();
}
Pila::Pila(std::string nombre)
{
	this->nombre = nombre;
	this->lista = std::vector<int>();
}

bool Pila::apilar(int disco) {
	if (this->lista.size() == 0) {
		this->lista.push_back(disco);
		return true;
	}
	int ultimo = this->lista[this->lista.size() - 1];
	if (ultimo > disco) {
		this->lista.push_back(disco);
		return true;
	}
	
	return false;
}
int Pila::desapilar() {
	if (this->lista.size()>0) {
		int retorno = this->lista[this->lista.size() - 1];
		this->lista.pop_back();
		return retorno;
	}
	return -1;
	
}



Pila::~Pila()
{
}
