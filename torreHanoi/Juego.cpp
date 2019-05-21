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