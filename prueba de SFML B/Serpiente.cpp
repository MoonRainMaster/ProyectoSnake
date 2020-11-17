#include "Serpiente.h"

Serpiente::Serpiente()
{
	for (int i = 0; i < 3; i++)
	{
		Push();
	}
}

void Serpiente::Push()
{
	if (!primero)
	{
		primero = new Nodo({ 400, 300 });
		ultimo = primero;
	}
	else
	{
		Nodo* provis = primero;

		while (provis->siguiente)
		{
			provis = provis->siguiente;
		}
		provis->siguiente = new Nodo(provis->GenerarSiguiente());
		provis->siguiente->anterior = provis;
		ultimo = provis->siguiente;
		ultimo->set_dir(provis->get_dir());
	}
}

void Serpiente::Pop()
{
	if (!primero)
	{
		primero = new Nodo({ 400, 300 });
		ultimo = primero;
	}
	else
	{
		Nodo* provis = primero;
		Nodo* aux;

		while (provis->siguiente)
		{
			provis = provis->siguiente;
		}
		del_rectangle();

	}
}

void Serpiente::Dibujar(RenderWindow& ventana)
{
	check_colision();

	Nodo* provis;

		if (ultimo)
		{
			provis = ultimo;

			while (provis)
			{
				provis->Dibujar(ventana);
				if (provis->anterior)
				{
					provis->set_dir(provis->anterior->get_dir());
				} 
				provis = provis->anterior;
			}
		}
}

void Serpiente::set_dir(unsigned short dir)
{
	if (primero)
	{
		primero->set_dir(dir);
	}
}

void Serpiente::check_colision()
{
	Nodo* provis;

	if (primero)
	{
		provis = primero->siguiente;

		while (provis)
		{
			if (primero->get_rectangle().getGlobalBounds().intersects(provis->get_rectangle().getGlobalBounds()))
			{
				system("PAUSE");
			}

			provis = provis->siguiente;
		}
	}
}

void Serpiente::del_rectangle()
{
	Nodo* anterior = this->ultimo->anterior;
	this->ultimo = anterior;
	if (anterior->siguiente != NULL)
	{
		anterior->siguiente = (nullptr);
	}
}
