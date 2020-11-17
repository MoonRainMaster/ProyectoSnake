#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Banano
{
public:
    Banano();
    void Dibujar(RenderWindow& ventana);
    RectangleShape get_rect() { return *spr_banano; }

private:
    RectangleShape* spr_banano;
    Vector2f coord;
};

