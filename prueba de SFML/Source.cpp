#include <SFML/Graphics.hpp>
#include <Windows.h>

using namespace sf;


int game = 1, dir=0, speed = 500, size = 1;
int randomx = 0, randomy = 0;
bool good = true;
struct Point {
    float x = 0;
    float y = 0;
}p[100];

int main()
{
   

    RenderWindow appWindow(sf::VideoMode(500, 500), "SNAKE");
    Event appEvent;
    
    Texture squaret, refresht, backgroundt;
    squaret.loadFromFile("square.png");
    refresht.loadFromFile("refresh.png");
    backgroundt.loadFromFile("2.png");

    Sprite orange(squaret), refresh(refresht), red(squaret), fondo(backgroundt);
    orange.setPosition(0, 0);
    orange.setColor(Color(255, 120, 0));
    red.setPosition(1000, 0);
    red.setColor(Color(255,0, 36));

    srand(time(NULL));
    randomx = 1 + rand() % (450);
    randomy = 1 + rand() % (450);
    for (int i = 0; i < 9; i++) {
        if (randomx <= (i + 1)*50 && randomx > i*50) randomx= (i + 1) * 50;
        if (randomy <= (i + 1) * 50 && randomy > i * 50) randomy = (i + 1) * 50;
    }

    while (appWindow.isOpen()) {
        
        while (appWindow.pollEvent(appEvent)) {
            if (appEvent.type == Event::Closed) {
                appWindow.close();
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

            if (p[0].x == red.getPosition().x && p[0].y == red.getPosition().y) {
                size += 1;
                if (speed > 100)speed -= 20;
                good = true;
                while (good) {
                    randomx = 1 + rand() % (450);
                    randomy = 1 + rand() % (450);
                    for (int i = 0; i < 9; i++) {
                        if (randomx <= (i + 1) * 50 && randomx > i * 50) randomx = (i + 1) * 50;
                        if (randomy <= (i + 1) * 50 && randomy > i * 50) randomy = (i + 1) * 50;
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
       
    }
    
    return 0;
}