#include "pch.h"
#include "Juego.h"


Juego::Juego()
{
}


Juego::~Juego()
{
}
Juego& Juego::GetInstance()
{
	static Juego instance;
	return instance;
}

void Juego::initialize() {
	switch (pantalla) {
	case MENU:
		break;
	}
}

void Juego::loadContent() {
	switch (pantalla) {
	case MENU:
		break;
	}

}

void Juego::unloadContent() {
	switch (pantalla) {
	case MENU:
		break;
	}

}

void Juego::update(ALLEGRO_EVENT ev, bool* done) {
	switch (pantalla) {
	case MENU:
		break;
	}

}

void Juego::draw(ALLEGRO_DISPLAY* display) {
	switch (pantalla) {
	case MENU:
		break;
	}

}

void Juego::cambiarPantalla(screen pantalla) {
	this->unloadContent();
	this->pantalla = pantalla;
	this->initialize();
	this->loadContent();
	dibujar = true;
}