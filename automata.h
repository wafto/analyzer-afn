#ifndef AUTOMATA_H
#define AUTOMATA_H

#include "estado.h"
#include "lista.h"
#include "pila.h"

class Automata {
	private:
		string Nombre;
		static int contador;
		Estado *edoInicial;
		Estado *edoAceptacion;
	public:
		// Constructores
		Automata();
		Automata(string Nom, Estado *Inicial, Estado *Aceptacion);
		Automata(char simbolo);		
		// Otros Metodos
		bool expresionReg(char simbolo);
		bool unionAfn(Automata *afn);
		bool concatena(Automata *afn);
		bool cerraduraPositiva();
		bool cerraduraEstrella();
		bool cerraduraInterrogacion();
		void displayTerminal();
		void displayAfdTabular();
		Estado *buscarEstado(int EdoId);
		Lista<Estado*> cerraduraEpsilon(Lista<int> EdoId);
		Lista<Estado*> cerraduraEpsilon(Lista<Estado*> Edos);
		Lista<Estado*> moverA(Lista<Estado*> E, char Simbolo);
		bool evaluaCadena(string cadena);
		Lista<char> getSimbolos();
		// Metodos Set
		void setEdoInicial(Estado *Inicial);
		void setEdoAceptacion(Estado *Aceptacion);
		void setNombre(string Nom);
		// Metodos Get
		Estado *getEdoInicial() const;
		Estado *getEdoAceptacion() const;
		string getNombre() const;
};


#endif


