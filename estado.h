#ifndef ESTADO_H
#define ESTADO_H

#define EPSILON '$'
#include <iostream>
#include <string>
using namespace std;

class Estado {
	private:
		int Identificador;
		Estado *Transicion1;
		Estado *Transicion2;
		char Simbolo1;
		char Simbolo2;
	public:
		// Constructores
		Estado();
		Estado(int id);
		Estado(int id, Estado *e1, char simbolo1);
		Estado(int id, Estado *e1, char simbolo1, Estado *e2, char simbolo2);
		// Otros Metodos
		void displayTerminal();
		// Metodos Set
		void setId(int id);
		void setTransicion1(Estado *estado);
		void setTransicion2(Estado *estado);
		void setSimbolo1(char simbolo);
		void setSimbolo2(char simbolo);
		// Metodos Get
		int getId() const;
		Estado *getTransicion1() const;
		Estado *getTransicion2() const;
		char getSimbolo1() const;
		char getSimbolo2() const;
};

#endif


