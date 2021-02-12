#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Manzana
{
public:
    Manzana();
    void Dibujar(RenderWindow &ventana);
    RectangleShape get_rect() { return *spr_manzana; }

private:
    RectangleShape* spr_manzana;
    Vector2f coord;
};

