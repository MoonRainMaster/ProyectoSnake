#include "Juego.h"

Juego::Juego(Vector2f resol, std::string titulo, int nivel)
{
	fps = 1 / 60.f;
	ventana1 = new RenderWindow(VideoMode(resol.x, resol.y), titulo);
	ventana1->setFramerateLimit(60);

	velocidad = 0.5;

	evento1 = new Event;

	reloj1 = new Clock;

	tiempo1 = new Time;

	jugador1 = new Serpiente;

	apple = new Manzana;
	
	switch (nivel)
	{
	case 2:
		velocidad = 0.3;
		ladrillo = new Ladrillo;
		ladrillo2 = new Ladrillo;
		columna1 = new Columna;
		break;
	case 3:
		velocidad = 0.1;
		ladrillo = new Ladrillo;
		ladrillo2 = new Ladrillo;
		columna1 = new Columna;
		columna2 = new Columna;
		pared = new Pared;
		break;
	default:
		break;
	}


	area_juego = new RectangleShape({720, 540});
	area_juego->setPosition({40, 30});
	area_juego->setFillColor(Color::Cyan);

	GameLoop();
}

void Juego::GameLoop()
{
	while (!GameOver)
	{
		check_colisions();

		ProcesarEventos();
		*tiempo1 = reloj1->getElapsedTime();
		if (tiempo1->asSeconds() > tiempo2 + velocidad) // modifica la velocidad
		{
			tiempo2 = tiempo1->asSeconds();
			Dibujar();
		}
	}
}

void Juego::Dibujar()
{
	ventana1->clear();

	//Dibuja los nuevos elementos

	ventana1->draw(*area_juego);

	if (apple != NULL)
	{
		apple->Dibujar(*ventana1);
	}
	if (fresa != NULL)
	{
		fresa->Dibujar(*ventana1);
	}
	if (banano != NULL)
	{
		banano->Dibujar(*ventana1);
	}
	if (pera != NULL)
	{
		pera->Dibujar(*ventana1);
	}
	if (pinia != NULL)
	{
		pinia->Dibujar(*ventana1);
	}
	if (ladrillo != NULL)
	{
		ladrillo->Dibujar(*ventana1);
	}
	if (ladrillo2 != NULL)
	{
		ladrillo2->Dibujar(*ventana1);
	}
	if (columna1 != NULL)
	{
		columna1->Dibujar(*ventana1);
	}
	if (columna2 != NULL)
	{
		columna2->Dibujar(*ventana1);
	}
	if (pared != NULL)
	{
		pared->Dibujar(*ventana1);
	}

	jugador1->Dibujar(*ventana1);

	//Dibujar nuevos elementos
	ventana1->display();
}

void Juego::ProcesarEventos()
{
	while (ventana1->pollEvent(*evento1))
	{
		switch (evento1->type)
		{
		case Event::Closed:
			exit(1);
			break;

		case Event::KeyPressed:
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				jugador1->set_dir(2);
			}
			else if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				jugador1->set_dir(3);
			}
			else if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				jugador1->set_dir(0);
			}
			else if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				jugador1->set_dir(1);
			}
			break;
		}
	}
}

void Juego::check_colisions()
{
	if (apple != NULL && jugador1->get_primero().get_rectangle().getGlobalBounds().intersects(apple->get_rect().getGlobalBounds()))
	{
		jugador1->Push();
		apple = NULL;
		int x = 1 + rand() % (99 - 1);

		if (x <= 5)
		{
			pinia = new Pinia;
		}
		else if (x <= 15)
		{
			pera = new Pera;
		}
		else if (x <= 35)
		{
			banano = new Banano;
		}
		else if (x <= 60)
		{
			fresa = new Fresa;
		}
		else if (x <= 100)
		{
			apple = new Manzana;
		}
	}
	else if (fresa != NULL && jugador1->get_primero().get_rectangle().getGlobalBounds().intersects(fresa->get_rect().getGlobalBounds()))
	{
		jugador1->Push();
		jugador1->Push();
		fresa = NULL;
		int x = 1 + rand() % (99 - 1);

		if (x <= 5)
		{
			pinia = new Pinia;
		}
		else if (x <= 15)
		{
			pera = new Pera;
		}
		else if (x <= 35)
		{
			banano = new Banano;
		}
		else if (x <= 60)
		{
			fresa = new Fresa;
		}
		else if (x <= 100)
		{
			apple = new Manzana;
		}
	}
	else if (banano != NULL && jugador1->get_primero().get_rectangle().getGlobalBounds().intersects(banano->get_rect().getGlobalBounds()))
	{
		jugador1->Push();
		jugador1->Push();
		jugador1->Push();
		banano = NULL;
		int x = 1 + rand() % (99 - 1);

		if (x <= 5)
		{
			pinia = new Pinia;
		}
		else if (x <= 15)
		{
			pera = new Pera;
		}
		else if (x <= 35)
		{
			banano = new Banano;
		}
		else if (x <= 60)
		{
			fresa = new Fresa;
		}
		else if (x <= 100)
		{
			apple = new Manzana;
		}
	}
	else if (pera != NULL && jugador1->get_primero().get_rectangle().getGlobalBounds().intersects(pera->get_rect().getGlobalBounds()))
	{
		jugador1->Pop();
		pera = NULL;
		int x = 1 + rand() % (99 - 1);

		if (x <= 5)
		{
			pinia = new Pinia;
		}
		else if (x <= 15)
		{
			pera = new Pera;
		}
		else if (x <= 35)
		{
			banano = new Banano;
		}
		else if (x <= 60)
		{
			fresa = new Fresa;
		}
		else if (x <= 100)
		{
			apple = new Manzana;
		}
	}
	else if (pinia != NULL && jugador1->get_primero().get_rectangle().getGlobalBounds().intersects(pinia->get_rect().getGlobalBounds()))
	{
		jugador1->Pop();
		jugador1->Pop();
		jugador1->Pop();
		jugador1->Pop();
		jugador1->Pop();
		pinia = NULL;
		int x = 1 + rand() % (99 - 1);

		if (x <= 5)
		{
			pinia = new Pinia;
		}
		else if (x <= 15)
		{
			pera = new Pera;
		}
		else if (x <= 35)
		{
			banano = new Banano;
		}
		else if (x <= 60)
		{
			fresa = new Fresa;
		}
		else if (x <= 100)
		{
			apple = new Manzana;
		}
	}
	else if (ladrillo != NULL && jugador1->get_primero().get_rectangle().getGlobalBounds().intersects(ladrillo->get_rect().getGlobalBounds()))
	{
	system("PAUSE");
	}
	else if (ladrillo2 != NULL && jugador1->get_primero().get_rectangle().getGlobalBounds().intersects(ladrillo2->get_rect().getGlobalBounds()))
	{
	system("PAUSE");
	}
	else if (columna1 != NULL && jugador1->get_primero().get_rectangle().getGlobalBounds().intersects(columna1->get_rect().getGlobalBounds()))
	{
	system("PAUSE");
	}
	else if (columna1 != NULL && jugador1->get_primero().get_rectangle().getGlobalBounds().intersects(columna1->get_rect2().getGlobalBounds()))
	{
	system("PAUSE");
	}
	else if (columna1 != NULL && jugador1->get_primero().get_rectangle().getGlobalBounds().intersects(columna1->get_rect3().getGlobalBounds()))
	{
	system("PAUSE");
	}
	else if (columna1 != NULL && jugador1->get_primero().get_rectangle().getGlobalBounds().intersects(columna1->get_rect4().getGlobalBounds()))
	{
	system("PAUSE");
	}
	else if (columna2 != NULL && jugador1->get_primero().get_rectangle().getGlobalBounds().intersects(columna2->get_rect().getGlobalBounds()))
	{
	system("PAUSE");
	}
	else if (columna2 != NULL && jugador1->get_primero().get_rectangle().getGlobalBounds().intersects(columna2->get_rect2().getGlobalBounds()))
	{
	system("PAUSE");
	}
	else if (columna2 != NULL && jugador1->get_primero().get_rectangle().getGlobalBounds().intersects(columna2->get_rect3().getGlobalBounds()))
	{
	system("PAUSE");
	}
	else if (columna2 != NULL && jugador1->get_primero().get_rectangle().getGlobalBounds().intersects(columna2->get_rect4().getGlobalBounds()))
	{
	system("PAUSE");
	}
	else if (pared != NULL && jugador1->get_primero().get_rectangle().getGlobalBounds().intersects(pared->get_rect().getGlobalBounds()))
	{
	system("PAUSE");
	}
	else if (pared != NULL && jugador1->get_primero().get_rectangle().getGlobalBounds().intersects(pared->get_rect2().getGlobalBounds()))
	{
	system("PAUSE");
	}
	else if (pared != NULL && jugador1->get_primero().get_rectangle().getGlobalBounds().intersects(pared->get_rect3().getGlobalBounds()))
	{
	system("PAUSE");
	}
	else if (pared != NULL && jugador1->get_primero().get_rectangle().getGlobalBounds().intersects(pared->get_rect4().getGlobalBounds()))
	{
	system("PAUSE");
	}
	else if (pared != NULL && jugador1->get_primero().get_rectangle().getGlobalBounds().intersects(pared->get_rect5().getGlobalBounds()))
	{
	system("PAUSE");
	}
	else if (pared != NULL && jugador1->get_primero().get_rectangle().getGlobalBounds().intersects(pared->get_rect6().getGlobalBounds()))
	{
	system("PAUSE");
	}
	else if (!area_juego->getGlobalBounds().contains(jugador1->get_primero().get_rectangle().getPosition()))
	{
		system("PAUSE");
	}
}
