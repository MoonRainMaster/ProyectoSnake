#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Fresa
{
public:
    Fresa();
    void Dibujar(RenderWindow& ventana);
    RectangleShape get_rect() { return *spr_fresa; }

private:
    RectangleShape* spr_fresa;
    Vector2f coord;
};
