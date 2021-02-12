#include "Banano.h"

Banano::Banano()
{
	coord.x = 1 + rand() % (19 - 1);
	coord.x *= 40;

	coord.y = 1 + rand() % (19 - 1);
	coord.y *= 30;

	spr_banano = new RectangleShape({ 40, 30 });
	spr_banano->setPosition(coord);
	spr_banano->setFillColor(Color::Yellow);
}

void Banano::Dibujar(RenderWindow& ventana)
{
	if (spr_banano != NULL)
	{
		ventana.draw(*spr_banano);
	}
}