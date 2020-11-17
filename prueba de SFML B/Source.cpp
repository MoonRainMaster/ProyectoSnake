#include <iostream>
#include "Juego.h"

using namespace std;

int main() {
	int x = 0;
	srand(time(NULL));

	Juego* partida1;
	while (x != 5)
	{
		printf("MENU\n1.FACIL\n2.MEDIO\n3.DIFICIL\n4.DINAMICO\n");
		cout << "INGRESE EL INVEL A JUGAR: "; cin >> x;
		switch (x)
		{
		case 1:
			partida1 = new Juego({ 800, 600 }, "Proyecto Snake", 1);
			break;
		case 2:
			partida1 = new Juego({ 800, 600 }, "Proyecto Snake", 2);
			break;
		case 3:
			partida1 = new Juego({ 800, 600 }, "Proyecto Snake", 3);
			break;
		case 4:
			break;
		}
	}
	return 0;
}