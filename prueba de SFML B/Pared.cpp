#include "Pared.h"

Pared::Pared()
{
	coord.x = 1 + rand() % (19 - 1);
	coord.x *= 40;

	coord.y = 1 + rand() % (19 - 1);
	coord.y *= 30;

	spr_pared = new RectangleShape({ 40, 30 });
	spr_pared->setPosition(coord);
	spr_pared->setFillColor(Color::Black);

	coord.x += 40;
	spr_pared2 = new RectangleShape({ 40, 30 });
	spr_pared2->setPosition(coord);
	spr_pared2->setFillColor(Color::Black);

	coord.x += 40;
	spr_pared3 = new RectangleShape({ 40, 30 });
	spr_pared3->setPosition(coord);
	spr_pared3->setFillColor(Color::Black);

	coord.x += 40;
	spr_pared4 = new RectangleShape({ 40, 30 });
	spr_pared4->setPosition(coord);
	spr_pared4->setFillColor(Color::Black);

	coord.x += 40;
	spr_pared5 = new RectangleShape({ 40, 30 });
	spr_pared5->setPosition(coord);
	spr_pared5->setFillColor(Color::Black);

	coord.x += 40;
	spr_pared6 = new RectangleShape({ 40, 30 });
	spr_pared6->setPosition(coord);
	spr_pared6->setFillColor(Color::Black);
}

void Pared::Dibujar(RenderWindow& ventana)
{
	ventana.draw(*spr_pared);
	ventana.draw(*spr_pared2);
	ventana.draw(*spr_pared3);
	ventana.draw(*spr_pared4);
	ventana.draw(*spr_pared5);
	ventana.draw(*spr_pared6);
}