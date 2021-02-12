#include "Pinia.h"

Pinia::Pinia()
{
	coord.x = 1 + rand() % (19 - 1);
	coord.x *= 40;

	coord.y = 1 + rand() % (19 - 1);
	coord.y *= 30;

	spr_pinia = new RectangleShape({ 40, 30 });
	spr_pinia->setPosition(coord);
	spr_pinia->setFillColor(Color::White);
}

void Pinia::Dibujar(RenderWindow& ventana)
{
	if (spr_pinia != NULL)
	{
		ventana.draw(*spr_pinia);
	}
}