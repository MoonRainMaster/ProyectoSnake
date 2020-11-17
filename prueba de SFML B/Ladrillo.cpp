#include "Ladrillo.h"

Ladrillo::Ladrillo()
{
	coord.x = 1 + rand() % (19 - 1);
	coord.x *= 40;

	coord.y = 1 + rand() % (19 - 1);
	coord.y *= 30;

	spr_ladrillo = new RectangleShape({ 40, 30 });
	spr_ladrillo->setPosition(coord);
	spr_ladrillo->setFillColor(Color::Black);
}

void Ladrillo::Dibujar(RenderWindow& ventana)
{
	ventana.draw(*spr_ladrillo);
}
