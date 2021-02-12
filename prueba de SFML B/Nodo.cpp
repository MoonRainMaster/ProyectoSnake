#include "Nodo.h"

Nodo::Nodo(Vector2f coord)
{
	coordenadas = coord;
	parte = new RectangleShape({40, 30});
	parte->setFillColor(Color::Green);
	parte->setPosition(coord);	
}

void Nodo::Dibujar(RenderWindow& ventana)
{
	Mover();
	ventana.draw(*parte);
}

void Nodo::Mover()
{
	switch (dir)
	{
	case 0: // Izq
		coordenadas.x -= 40;	
		break;
	case 1: //Der
		coordenadas.x += 40;
		break;
	case 2: //Arr
		coordenadas.y -= 30;
		break;
	case 3: //Abajo
		coordenadas.y += 30;
		break;
	}
	parte->setPosition(coordenadas);
}

Vector2f Nodo::GenerarSiguiente()
{
	Vector2f coord = { 0, 0 };
	coord = coordenadas;
	switch (dir)
	{
	case 0: // Izq
		coord.x += 40;
		break;
	case 1: //Der
		coord.x -= 40;
		break;
	case 2: //Arr
		coord.y += 30;
		break;
	case 3: //Abajo
		coord.y -= 30;
		break;
	}
	return coord;
}