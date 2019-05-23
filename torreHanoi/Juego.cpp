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
		this->inicial->apilar(3);
		this->inicial->apilar(2);
		this->inicial->apilar(1);
		this->inicial->apilar(0);
		this->posTorreInicial = std::make_pair(127, 401);
		this->posTorreInter = std::make_pair(325, 401);
		this->posTorreFinal = std::make_pair(513,401);
		select = -1;

		break;
	}
}

void Juego::loadContent() {
	switch (pantalla) {
	case 0:
		fuente = al_load_font("Aluria.ttf", 26, NULL);
		menu.push_back("Iniciar");
		menu.push_back("Salir");
		break;
	case 1:
		fuente = al_load_font("Aluria.ttf", 46, NULL);
		tablero = al_load_bitmap("tablero.png");
		break;
	}

}

void Juego::unloadContent() {
	switch (pantalla) {
	case 0:
		al_destroy_font(fuente);
		menu.clear();
		break;
	case 1:
		this->final->lista.clear();
		this->intermedia->lista.clear();
		al_destroy_font(fuente);
		al_destroy_bitmap(tablero);
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
	case 1:
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (ev.mouse.button & 1)
			{
				float mouseY = ev.mouse.y;
				float mouseX = ev.mouse.x;
				// 234 de largo
				// 79 de angosto
				if (mouseY > 30 && mouseY<70  && mouseX > 550) {
					cambiarPantalla(0);
					dibujar = true;
					break;
				}
				if (posTorreInicial.first - 76 < mouseX &&  posTorreInicial.first + 76 > mouseX && posTorreInicial.second > mouseY && posTorreInicial.second  - 234 < mouseY) {
					dibujar = true;
					int disco;
					if(select == -1 || select == 0) select = 0;
					else {
						switch (select) {
						case 1:
							if (this->intermedia->lista.size() > 0) {
								disco = this->intermedia->desapilar();
								if (!this->inicial->apilar(disco)) {
									this->intermedia->apilar(disco);
								}
							}
							break;
						case 2:
							if (this->final->lista.size() > 0) {
								disco = this->final->desapilar();
								if (!this->inicial->apilar(disco)) {
									this->final->apilar(disco);
								}
							}
							break;
						}
						select = -1;
					}
				}
				if (posTorreInter.first - 76 < mouseX &&  posTorreInter.first + 76 > mouseX && posTorreInter.second > mouseY && posTorreInter.second - 234 < mouseY) {
					dibujar = true;
					int disco;
					if (select == -1 || select == 1) select = 1;
					else {
						switch (select) {
						case 0:
							if (this->inicial->lista.size() > 0) {
								disco = this->inicial->desapilar();
								if (!this->intermedia->apilar(disco)) {
									this->inicial->apilar(disco);
								}
							}
							break;
						case 2:
							if (this->final->lista.size() > 0) {
								disco = this->final->desapilar();
								if (!this->intermedia->apilar(disco)) {
									this->final->apilar(disco);
								}
							}
							break;
						}
						select = -1;
					}
				}
				if (posTorreFinal.first - 76 < mouseX &&  posTorreFinal.first + 76 > mouseX && posTorreFinal.second > mouseY && posTorreFinal.second - 234 < mouseY) {
					dibujar = true;
					int disco;
					if (select == -1 || select == 2) select = 2;
					else {
						switch (select) {
						case 0:
							if (this->inicial->lista.size() >0) {
								disco = this->inicial->desapilar();
								if (!this->final->apilar(disco)) {
									this->inicial->apilar(disco);
								}
							}
							break;
						case 1:
							if (this->intermedia->lista.size() > 0) {
								disco = this->intermedia->desapilar();
								if (!this->final->apilar(disco)) {
									this->intermedia->apilar(disco);
								}
							}
							break;
						}
						select = -1;
					}
				}
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
		al_draw_bitmap(tablero, 0, 0, NULL);
		for (int i = 0; i < this->inicial->lista.size(); i++) {
			al_draw_filled_rectangle(posTorreInicial.first + 10 * this->inicial->lista[i], posTorreInicial.second - 10 * i, posTorreInicial.first + 20 + 10* this->inicial->lista[i], posTorreInicial.second - 10 - 10 * i, al_map_rgb(this->inicial->lista[i]*30, 0, 0));
			al_draw_filled_rectangle(posTorreInicial.first + 10 * this->inicial->lista[i], posTorreInicial.second - 10 * i, posTorreInicial.first - 20 - 10* this->inicial->lista[i], posTorreInicial.second - 10 - 10 * i, al_map_rgb(this->inicial->lista[i]*30, 0, 0));
		}
		for (int i = 0; i < this->intermedia->lista.size(); i++) {
			al_draw_filled_rectangle(posTorreInter.first + 10 * this->intermedia->lista[i], posTorreInter.second - 10 * i, posTorreInter.first + 20 + 10 * this->intermedia->lista[i], posTorreInter.second - 10 - 10 * i, al_map_rgb(this->intermedia->lista[i]*30, 0, 0));
			al_draw_filled_rectangle(posTorreInter.first + 10 * this->intermedia->lista[i], posTorreInter.second - 10 * i, posTorreInter.first - 20 - 10 * this->intermedia->lista[i], posTorreInter.second - 10 - 10 * i, al_map_rgb(this->intermedia->lista[i]*30, 0, 0));
		}
		for (int i = 0; i < this->final->lista.size(); i++) {
			al_draw_filled_rectangle(posTorreFinal.first + 10 * this->final->lista[i], posTorreFinal.second - 10 * i, posTorreFinal.first + 20 + 10 * this->final->lista[i], posTorreFinal.second - 10 - 10 * i, al_map_rgb(this->final->lista[i]*30, 0, 0));
			al_draw_filled_rectangle(posTorreFinal.first + 10 * this->final->lista[i], posTorreFinal.second - 10 * i, posTorreFinal.first - 20 - 10 * this->final->lista[i], posTorreFinal.second - 10 - 10 * i, al_map_rgb(this->final->lista[i]*30, 0, 0));
		}

		switch (select) {
		case 0:
			al_draw_filled_triangle(posTorreInicial.first, 162, posTorreInicial.first - 20, 162 - 20, posTorreInicial.first + 20, 162 - 20, al_map_rgb(191, 65, 65));
			break;
		case 1:
			al_draw_filled_triangle(posTorreInter.first, 162, posTorreInter.first - 20, 162 - 20, posTorreInter.first + 20, 162 - 20, al_map_rgb(191, 65, 65));
			break;
		case 2:
			al_draw_filled_triangle(posTorreFinal.first, 162, posTorreFinal.first - 20, 162 - 20, posTorreFinal.first + 20, 162 - 20, al_map_rgb(191, 65, 65));
			break;
		}

		al_draw_text(fuente, al_map_rgb(219, 90, 48), 550, 20, NULL, "salir");
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