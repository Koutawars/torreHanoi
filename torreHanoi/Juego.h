#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <utility>
#include "Pila.h"

#pragma once


class Juego
{
public:
	bool ayuda=false;
	Pila* inicial = new Pila("inicial");
	Pila* intermedia = new Pila("intermedia");
	Pila* final = new Pila("final");
	static Juego & GetInstance();
	void initialize();
	void loadContent();
	std::vector < std::string > menu;
	void unloadContent();
	void update(ALLEGRO_EVENT ev, bool* done);
	void draw(ALLEGRO_DISPLAY* display);
	int pantalla = 0;
	bool dibujar = true;
	void cambiarPantalla(int pantalla);
	void resultado();
	void hanoi(int Fichas, Pila* torre1, Pila* torre2, Pila* torre3);
	std::vector <std::pair<Pila*, Pila*>> resultadoHanoi;
	ALLEGRO_FONT* fuente;
	float posXMenu; // posición X del menu
	float posYMenu; // posición Y del menu
	float separador; // separador entre texto
	int select; // Para guardar a quien esta colocando el mouse encima del menu

	std::pair<int, int> posTorreInicial;
	std::pair<int, int> posTorreInter;
	std::pair<int, int> posTorreFinal;

	int pasos;
	bool sigue;

	ALLEGRO_BITMAP *tablero;

	Juego();
	~Juego();
};

