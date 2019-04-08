#include "estado.h"

// Constructores
Estado::Estado(){
	Identificador = 0;
};
Estado::Estado(int id){
	Identificador = id;
	Transicion1 = NULL;
	Simbolo1 = EPSILON;
	Transicion2 = NULL;
	Simbolo2 = EPSILON;
};
Estado::Estado(int id, Estado *e1, char simbolo1){
	Identificador = id;
	Transicion1 = e1;
	Simbolo1 = simbolo1;
	Transicion2 = NULL;
	Simbolo2 = EPSILON;
};
Estado::Estado(int id, Estado *e1, char simbolo1, Estado *e2, char simbolo2){
	Identificador = id;
	Transicion1 = e1;
	Simbolo1 = simbolo1;
	Transicion1 = e2;
	Simbolo1 = simbolo2;
};

//Otros Metodos
void Estado::displayTerminal(){
	if(Transicion1!=NULL)
		cout<<"\t( "<< Identificador <<", "<< Simbolo1 <<" )"<<" -> "<<Transicion1->getId()<<endl;
	if(Transicion2!=NULL)
		cout<<"\t( "<< Identificador <<", "<< Simbolo2 <<" )"<<" -> "<<Transicion2->getId()<<endl;
	if(Transicion1==NULL && Transicion2==NULL)
		cout<<"\tSin conexiones."<<endl;
};

// Metodos Set
void Estado::setId(int id){
	Identificador = id;
};
void Estado::setTransicion1(Estado *estado){
	Transicion1 = estado;
};
void Estado::setTransicion2(Estado *estado){
	Transicion2 = estado;
};
void Estado::setSimbolo1(char simbolo){
	Simbolo1 = simbolo;
};
void Estado::setSimbolo2(char simbolo){
	Simbolo2 = simbolo;
};

// Metodos Get
int Estado::getId()const {
	return Identificador;
};
Estado *Estado::getTransicion1()const {
	return Transicion1;
};
Estado *Estado::getTransicion2()const {
	return Transicion2;
};
char Estado::getSimbolo1()const {
	return Simbolo1;
};
char Estado::getSimbolo2()const {
	return Simbolo2;
};




