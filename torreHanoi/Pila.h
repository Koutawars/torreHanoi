#pragma once
#include <vector>
class Pila
{
public:
	Pila();
	std::vector<int> lista;
	bool desapilar();
	bool apilar(int dico);
	~Pila();
};

