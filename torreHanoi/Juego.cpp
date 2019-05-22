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
	case 0:
		menu = std::vector<std::string>();
		posXMenu = 300;
		posYMenu = 150;
		separador = 55;
		select = -1;
		break;
	case 1:
		this->inicial->apilar(0);
		this->inicial->apilar(1);
		this->inicial->apilar(2);
		this->inicial->apilar(3);
		break;
	}
}

void Juego::loadContent() {
	switch (pantalla) {
	case 0:
		fuente = al_load_font("Aluria.ttf", 26, NULL);
		menu.push_back("Iniciar");
		menu.push_back("Detalles");
		menu.push_back("Salir");
		break;
	}

}

void Juego::unloadContent() {
	switch (pantalla) {
	case 0:
		al_destroy_font(fuente);
		menu.clear();
		break;
	}

}

void Juego::update(ALLEGRO_EVENT ev, bool* done) {
	switch (pantalla) {
	case 0:
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (ev.mouse.button & 1)
			{
				float mouseY = ev.mouse.y;
				for (int i = 0; i < menu.size(); i++) {
					int posicionTexto = separador * i + posYMenu;
					if (posicionTexto < mouseY && posicionTexto + separador > mouseY) {
						switch (i) {
						case 0:
							cambiarPantalla(1);
							break;
						case 1:
							cambiarPantalla(2);
							break;
						case 2:
							*done = true;
							break;
						}
					}
				}
			}
		}
		if (ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
			float mouseY = ev.mouse.y;
			bool encontrado = false;
			for (int i = 0; i < menu.size(); i++) {
				int posicionTexto = separador * i + posYMenu;
				if (posicionTexto < mouseY && posicionTexto + separador > mouseY) {
					select = i;
					dibujar = true;
					encontrado = true;
				}
			}
			if (!encontrado && select != -1) {
				select = -1;
				dibujar = true;
			}
		}
		break;
	}

}

void Juego::draw(ALLEGRO_DISPLAY* display) {
	switch (pantalla) {
	case 0:
		for (int i = 0; i < menu.size(); i++) {

			al_draw_text(fuente, al_map_rgb(219, 90, 48), posXMenu, (i * separador) + posYMenu, NULL, menu[i].c_str());
			
		}
		break;
	case 1:

		break;
	}

}

void Juego::cambiarPantalla(int pantalla) {
	this->unloadContent();
	this->pantalla = pantalla;
	this->initialize();
	this->loadContent();
	dibujar = true;
}