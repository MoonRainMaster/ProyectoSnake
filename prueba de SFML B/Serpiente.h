#pragma once
#include "Nodo.h"

class Serpiente
{
public:
	Serpiente();
	void Push();
	void Pop();
	void Dibujar(RenderWindow &ventana);
	void set_dir(unsigned short dir);
	void check_colision();
	Nodo get_primero() { return *primero; }
	void del_rectangle();
private:
	Nodo* primero = NULL;
	Nodo* ultimo = NULL;
};

