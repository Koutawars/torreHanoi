#pragma once
#include <vector>
#include <string>
class Pila
{
public:

	Pila();
	Pila(std::string nombre);
	std::vector<int> lista;
	int desapilar();
	std::string nombre;
	bool apilar(int dico);
	~Pila();
};

