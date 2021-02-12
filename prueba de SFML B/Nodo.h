#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Nodo
{
public:
	Nodo(Vector2f coord);
	void Dibujar(RenderWindow &ventana);
	Nodo* siguiente = NULL;
	Nodo* anterior = NULL;
	void Mover();
	Vector2f GenerarSiguiente();
	Vector2f get_coord() { return coordenadas; };
	unsigned short get_dir() { return dir; }
	void set_dir(unsigned short direccion) { dir = direccion; }
	RectangleShape get_rectangle() { return *parte; }
private:
	RectangleShape* parte;
	Vector2f coordenadas;
	unsigned short dir = 1; //0 izquierda, 1 derecha, 2 arriba, 3 abajo
};