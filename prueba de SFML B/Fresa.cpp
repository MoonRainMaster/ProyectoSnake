#include "Fresa.h"

Fresa::Fresa()
{
	coord.x = 1 + rand() % (19 - 1);
	coord.x *= 40;

	coord.y = 1 + rand() % (19 - 1);
	coord.y *= 30;

	spr_fresa = new RectangleShape({ 40, 30 });
	spr_fresa->setPosition(coord);
	spr_fresa->setFillColor(Color::Magenta);
}

void Fresa::Dibujar(RenderWindow& ventana)
{
	if (spr_fresa != NULL)
	{
		ventana.draw(*spr_fresa);
	}
}