#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Pinia
{
public:
    Pinia();
    void Dibujar(RenderWindow& ventana);
    RectangleShape get_rect() { return *spr_pinia; }

private:
    RectangleShape* spr_pinia;
    Vector2f coord;
};

