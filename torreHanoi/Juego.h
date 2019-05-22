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

#pragma once

enum screen {
	MENU,
	GAMEPLAY,
	ABOUT
};

class Juego
{
public:
	static Juego & GetInstance();
	void initialize();
	void loadContent();
	void unloadContent();
	void update(ALLEGRO_EVENT ev, bool* done);
	void draw(ALLEGRO_DISPLAY* display);
	screen pantalla = MENU;
	bool dibujar;
	void cambiarPantalla(screen pantalla);

	Juego();
	~Juego();
};

