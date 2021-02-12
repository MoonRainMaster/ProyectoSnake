#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Pera
{
public:
    Pera();
    void Dibujar(RenderWindow& ventana);
    RectangleShape get_rect() { return *spr_pera; }

private:
    RectangleShape* spr_pera;
    Vector2f coord;
};


