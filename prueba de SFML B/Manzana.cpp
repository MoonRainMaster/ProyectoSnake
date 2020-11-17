#include "Manzana.h"

Manzana::Manzana()
{
	coord.x = 1 + rand() % (19-1);
	coord.x *= 40;
	
	coord.y = 1 + rand() % (19-1);
	coord.y *= 30;

	spr_manzana = new RectangleShape({40, 30});
	spr_manzana->setPosition(coord);
	spr_manzana->setFillColor(Color::Red);
}

void Manzana::Dibujar(RenderWindow& ventana)
{
	ventana.draw(*spr_manzana);
}
