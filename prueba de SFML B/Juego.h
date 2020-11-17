#pragma once
#include <SFML/Graphics.hpp>
#include "Serpiente.h"
#include "Manzana.h"
#include "Fresa.h"
#include "Banano.h"
#include "Pera.h"
#include "Pinia.h"
#include "Ladrillo.h"
#include "Columna.h"
#include "Pared.h"

using namespace sf;

class Juego
{
public:
	Juego(Vector2f resol, std::string titulo, int nivel);
	void GameLoop();
	void Dibujar();
	void ProcesarEventos();
	void check_colisions();

private:
	RenderWindow* ventana1;

	Event* evento1;

	Clock* reloj1;
	Time* tiempo1;
	float tiempo2, fps;
	bool GameOver;
	
	Serpiente* jugador1 = NULL;
	Manzana* apple = NULL;
	Fresa* fresa = NULL;
	Banano* banano = NULL;
	Pera* pera = NULL;
	Pinia* pinia = NULL;
	float velocidad;
	Ladrillo* ladrillo = NULL;
	Ladrillo* ladrillo2 = NULL;
	Columna* columna1 = NULL;
	Columna* columna2 = NULL;
	Pared* pared = NULL;

	RectangleShape* area_juego = NULL;
};

