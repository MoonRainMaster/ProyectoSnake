#pragma once
#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Pared
{
public:
    Pared();
    void Dibujar(RenderWindow& ventana);
    RectangleShape get_rect() { return *spr_pared; }
    RectangleShape get_rect2() { return *spr_pared2; }
    RectangleShape get_rect3() { return *spr_pared3; }
    RectangleShape get_rect4() { return *spr_pared4; }
    RectangleShape get_rect5() { return *spr_pared5; }
    RectangleShape get_rect6() { return *spr_pared6; }

private:
    RectangleShape* spr_pared;
    RectangleShape* spr_pared2;
    RectangleShape* spr_pared3;
    RectangleShape* spr_pared4;
    RectangleShape* spr_pared5;
    RectangleShape* spr_pared6;
    Vector2f coord;
};

