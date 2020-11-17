#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <SFML/Audio.hpp>

using namespace sf;


int game = 1, dir=0, speed = 400, size = 1;
int randomx = 0, randomy = 0;
bool good = true;
struct Point {
    float x = 0;
    float y = 0;
}p[100];

int main()
{
   

    RenderWindow appWindow(sf::VideoMode(700, 700), "SNAKE");
    Event appEvent;
    
    Texture squaret, refresht, backgroundt,botont;
    squaret.loadFromFile("cabezaS.png");
    refresht.loadFromFile("manzana2.png");
    backgroundt.loadFromFile("background.png");
    botont.loadFromFile("boton1.png");

    Sprite orange(squaret), refresh(refresht), red(refresht), fondo(backgroundt),r(botont);
    orange.setPosition(0, 0);
    orange.setScale(0.4f, 0.4f);
    red.setPosition(1000, 0);
    red.setScale(0.2f, 0.2f);
    r.setScale(0.2f, 0.2f);

    
    
    //Genera la primaera mazana en una posición aleatoria
    srand(time(NULL));
    randomx = 1 + rand() % (550);
    randomy = 1 + rand() % (550);
    for (int i = 0; i < 9; i++) {
        if (randomx <= (i + 1)* 100 && randomx > i* 100) randomx= (i + 1) * 100;
        if (randomy <= (i + 1)* 100 && randomy > i* 100) randomy = (i + 1) * 100;
    }
    
    while (appWindow.isOpen()) {
        Vector2i pos = Mouse::getPosition(appWindow);
        while (appWindow.pollEvent(appEvent)) {
            if (appEvent.type == Event::Closed) {
                appWindow.close();
            }
            if (appEvent.type == Event::MouseButtonReleased) {
                if (appEvent.key.code == Mouse::Left) {
                    if (r.getGlobalBounds().contains(pos.x, pos.y)) {
                        if (game == 2) {
                            game = 1;
                            r.setPosition(1000, 0);
                            size = 1;
                            p[0].x = 0;
                            p[0].y = 0;
                            dir = 0;
                            speed = 700;
                            good = true;
                            while (good) {
                                randomx = 1 + rand() % (550);
                                randomy = 1 + rand() % (550);
                                for (int i = 0; i < 9; i++) {
                                    if (randomx <= (i + 1) * 100 && randomx > i * 100) randomx = (i + 1) * 100;
                                    if (randomy <= (i + 1) * 100 && randomy > i * 100) randomy = (i + 1) * 100;
                                }
                                for (int i = 0; i < size; i++) {
                                    if (randomx != p[i].x || randomy != p[i].y) good = false;
                                }
                            }
                        }
                    }
                }
            }
            if (appEvent.type == Event::KeyPressed) {
                if (game == 1) {
                    if (appEvent.key.code == Keyboard::Right && dir!= 1) dir = 0;
                    else if (appEvent.key.code == Keyboard::Left && dir!= 0) dir = 1;
                    else if (appEvent.key.code == Keyboard::Down && dir!= 3) dir = 2;
                    else if (appEvent.key.code == Keyboard::Up && dir!= 2) dir = 3;
                }
            }
        }

       
        appWindow.clear(Color(26, 28, 36));
        if (game == 1) {
            refresh.setPosition(1000, 0);
            appWindow.draw(fondo);
            for (int i = size; i > 0; i--) {
                p[i].x = p[i - 1].x;
                p[i].y = p[i - 1].y;
            }
            if (dir == 0)p[0].x += 50;
            if (dir == 1)p[0].x -= 50;
            if (dir == 2)p[0].y += 50;
            if (dir == 3)p[0].y -= 50;

            if (p[0].x == 700 || p[0].x == -50 || p[0].y == 700 || p[0].y == -50) game = 2;
            for (int i = 1; i < size; i++) {
                if(p[0].x==p[i].x && p[0].y==p[i].y)game=2;
            }
            if (p[0].x == red.getPosition().x && p[0].y == red.getPosition().y) {
                size += 1;
                if (speed > 100)speed -= 20;
                good = true;
                while (good) {
                    randomx = 1 + rand() % (550);
                    randomy = 1 + rand() % (550);
                    for (int i = 0; i < 9; i++) {
                        if (randomx <= (i + 1) * 100 && randomx > i * 100) randomx = (i + 1) * 100;
                        if (randomy <= (i + 1) * 100 && randomy > i * 100) randomy = (i + 1) * 100;
                    }
                    for (int i = 0; i < size; i++) {
                        if (randomx == p[i].x && randomy == p[i].y) {
                            break;
                        }
                        else if ((randomx != p[i].x || randomx != p[i].y) && i == size - 1) {
                            good = false;
                        }
                    }
                }
            }
            
            red.setPosition(randomx, randomy);
            appWindow.draw(red);

            for (int i = 0; i < size; i++) {
                orange.setPosition(p[i].x, p[i].y);
                appWindow.draw(orange);
            }
            
            appWindow.display();
            Sleep(speed);
        }
        else if (game == 2) {
            appWindow.draw(fondo);
            r.setPosition(200, 200);
            appWindow.draw(r);
            appWindow.display();
        }
       
    }
    
    return 0;
}