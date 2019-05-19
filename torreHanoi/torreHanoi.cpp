// torreHanoi.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "pch.h"
#include <iostream>
#include "Pila.h"
void hanoi(int Fichas, Pila* torre1, Pila* torre2, Pila* torre3);

int main()
{
	Pila *ptr = new Pila("inicial");
	ptr->apilar(4);
	ptr->apilar(3);
	ptr->apilar(2);
	ptr->apilar(1);
	Pila* ptr1 = new Pila("intermedia");
	Pila* ptr2 = new Pila("final");
	int tamano = ptr->lista.size();
	hanoi(tamano, ptr, ptr1, ptr2);
	for (int i = 0; i < ptr->lista.size(); i++)
	{
		std::cout << "torre 1 :" << ptr->lista[i] << std::endl;
	}
	for (int i = 0; i < ptr1->lista.size(); i++)
	{
		std::cout << "torre 2 :" << ptr1->lista[i] << std::endl;
	}
	for (int i = 0; i < ptr2->lista.size(); i++)
	{
		std::cout << "torre 3 :" << ptr2->lista[i] << std::endl;
	}


}
void hanoi(int Fichas, Pila* torre1, Pila* torre2, Pila* torre3) {
	int num_movimientos = 0;
	if (Fichas == 1) {
		std::cout << "mover el dico de " << torre1->nombre << " a " << torre3->nombre << std::endl;
		torre3->apilar(torre1->desapilar());
		num_movimientos++;
	}
	else {
		hanoi(Fichas - 1, torre1, torre3, torre2);
		std::cout << "mover el dico de " << torre1->nombre << " a " << torre3->nombre << std::endl;
		torre3->apilar(torre1->desapilar());
		hanoi(Fichas - 1, torre2, torre1, torre3);
	}
	
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
