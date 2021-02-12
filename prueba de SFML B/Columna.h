#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Columna
{
public:
    Columna();
    void Dibujar(RenderWindow& ventana);
    RectangleShape get_rect() { return *spr_columna; }
    RectangleShape get_rect2() { return *spr_columna2; }
    RectangleShape get_rect3() { return *spr_columna3; }
    RectangleShape get_rect4() { return *spr_columna4; }

private:
    RectangleShape* spr_columna;
    RectangleShape* spr_columna2;
    RectangleShape* spr_columna3;
    RectangleShape* spr_columna4;
    Vector2f coord;
};

