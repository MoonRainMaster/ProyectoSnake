#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ladrillo
{
public:
    Ladrillo();
    void Dibujar(RenderWindow& ventana);
    RectangleShape get_rect() { return *spr_ladrillo; }

private:
    RectangleShape* spr_ladrillo;
    Vector2f coord;
};


