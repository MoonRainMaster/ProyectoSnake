#include "Pera.h"

Pera::Pera()
{
	coord.x = 1 + rand() % (19 - 1);
	coord.x *= 40;

	coord.y = 1 + rand() % (19 - 1);
	coord.y *= 30;

	spr_pera = new RectangleShape({ 40, 30 });
	spr_pera->setPosition(coord);
	spr_pera->setFillColor(Color::Blue);
}

void Pera::Dibujar(RenderWindow& ventana)
{
	if (spr_pera != NULL)
	{
		ventana.draw(*spr_pera);
	}
}