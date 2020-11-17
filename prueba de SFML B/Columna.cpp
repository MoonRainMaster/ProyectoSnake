#include "Columna.h"

Columna::Columna()
{
		coord.x = 1 + rand() % (19 - 1);
		coord.x *= 40;

		coord.y = 1 + rand() % (19 - 1);
		coord.y *= 30;

		spr_columna = new RectangleShape({ 40, 30 });
		spr_columna->setPosition(coord);
		spr_columna->setFillColor(Color::Black);

		coord.y += 30;
		spr_columna2 = new RectangleShape({ 40, 30 });
		spr_columna2->setPosition(coord);
		spr_columna2->setFillColor(Color::Black);

		coord.y += 30;
		spr_columna3 = new RectangleShape({ 40, 30 });
		spr_columna3->setPosition(coord);
		spr_columna3->setFillColor(Color::Black);

		coord.y += 30;
		spr_columna4 = new RectangleShape({ 40, 30 });
		spr_columna4->setPosition(coord);
		spr_columna4->setFillColor(Color::Black);
}

void Columna::Dibujar(RenderWindow& ventana)
{
	ventana.draw(*spr_columna);
	ventana.draw(*spr_columna2);
	ventana.draw(*spr_columna3);
	ventana.draw(*spr_columna4);
}