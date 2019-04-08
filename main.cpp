
#include "automata.h"
#include <stdlib.h>
#include <stdio.h>

int menu(); 

int main()
{
	Automata *A[50];
	Automata *Aux1, *Aux2;
	string cadenaEvaluar;
	int indice = 0;
	int creados = 0;
	int a1, a2;
	bool res;
		
	while(1){
		int opc = menu();
		if((opc<0 || opc>11)) continue;
		switch(opc){
			case 1: {
				char simbolo;
				cout<<"\tPor favor indique el simbolo para el Automata : ";
				cin>>simbolo;
				A[indice] = new Automata(simbolo);
				cout<<"-----------------------------------------------"<<endl;
				cout<<"\tAutomata creado!"<<endl;
				A[indice]->displayTerminal();
				indice++; creados++;
				cout<<"-----------------------------------------------"<<endl;
				}
				break;
			case 2: {
				cout<<"-----------------------------------------------"<<endl;
				cout<<"\tUnion de Automatas "<<endl;
				cout<<"-----------------------------------------------\n"<<endl;
				cout<<"\nUnir el automata con id : "; cin>>a1;
				cout<<"\nUnir el automata con id : "; cin>>a2;
				if(a1<0 || a2<0 || a1>creados-1 || a2>creados-1 || a1==a2 || A[a1]==NULL || A[a2]==NULL){
					cout<<"\n##### No se pudo unir los automatas. #####"<<endl;
					continue;}
				A[a1]->unionAfn(A[a2]);
				A[a2] = NULL;
				A[a1]->displayTerminal();
				}
				break;
			case 3: {
				cout<<"-----------------------------------------------"<<endl;
				cout<<"\tConcatenacion de Autonomas "<<endl;
				cout<<"-----------------------------------------------\n"<<endl;
				cout<<"Unir el automata con id : "; cin>>a1;
				cout<<"\nUnir el automata con id : "; cin>>a2;
				if(a1<0 || a2<0 || a1>creados-1 || a2>creados-1 || a1==a2 || A[a1]==NULL || A[a2]==NULL){
					cout<<"\n##### No se pudo unir los automatas. #####"<<endl;
					continue;
				}
				A[a1]->concatena(A[a2]);
				A[a2] = NULL;
				A[a1]->displayTerminal();
				}
				break;
			case 4: {
				cout<<"-----------------------------------------------"<<endl;
				cout<<"\tCerradura Positiva a un Autonoma "<<endl;
				cout<<"-----------------------------------------------\n"<<endl;
				cout<<"Crear cerradura(+) al automata con id : "; cin>>a1;
				if(a1<0 || a1>creados-1 || A[a1]==NULL){
					cout<<"\n##### No se pudo realizar la operacion. #####"<<endl;
					continue;
				}
				A[a1]->cerraduraPositiva();
				A[a1]->displayTerminal();
				}
				break;
			case 5: {
				cout<<"-----------------------------------------------"<<endl;
				cout<<"\tCerradura Estrella a un Autonoma "<<endl;
				cout<<"-----------------------------------------------\n"<<endl;
				cout<<"Crear cerradura(*) al automata con id : "; cin>>a1;
				if(a1<0 || a1>creados-1 || A[a1]==NULL){
					cout<<"\n##### No se pudo realizar la operacion. #####"<<endl;
					continue;
				}
				A[a1]->cerraduraEstrella();
				A[a1]->displayTerminal();
				}
				break;
			case 6: {
				cout<<"-----------------------------------------------"<<endl;
				cout<<"\tCerradura Interrogacion a un Autonoma "<<endl;
				cout<<"-----------------------------------------------\n"<<endl;
				cout<<"Crear cerradura(?) al automata con id : "; cin>>a1;
				if(a1<0 || a1>creados-1 || A[a1]==NULL){
					cout<<"\n##### No se pudo realizar la operacion. #####"<<endl;
					continue;
				}
				A[a1]->cerraduraInterrogacion();
				A[a1]->displayTerminal();
				}
				break;
			case 7: {
				cout<<"-----------------------------------------------"<<endl;
				cout<<"\tEvaluar cadena en un Autonoma "<<endl;
				cout<<"-----------------------------------------------\n"<<endl;
				cout<<"Evaluar cadena con el automata con id : "; cin>>a1;
				if(a1<0 || a1>creados-1 || A[a1]==NULL){
					cout<<"\n##### No se pudo realizar la operacion. #####"<<endl;
					continue;
				}
				cout<<"Cadena que desea evaluar :"; cin>>cadenaEvaluar;
				res = A[a1]->evaluaCadena(cadenaEvaluar);
				if(res==true) cout<<"La cadena es valida!!!"<<endl;
				if(res==false) cout<<"La cadena NO es valida!!!"<<endl;
				}
				break;
			case 8: {/*
				Automata *A = new Automata('a');
				Automata *B = new Automata('b');
				Automata *C = new Automata('c');
				Automata *D = new Automata('d');
				Automata *E = new Automata('e');
				A->unionAfn(B);
				A->concatena(C);
				A->unionAfn(D);
				A->concatena(E);
				A->cerraduraEstrella();
				A->cerraduraPositiva();
				A->cerraduraInterrogacion();
				Lista<char> letras = A->getSimbolos();
				for(int i=0; i<letras.numElem(); i++)
					cout<< letras.getInfoAt(i) <<endl;*/
				}
				break;
			case 9: {
				cout<<"-----------------------------------------------"<<endl;
				cout<<"\tListado de Automatas"<<endl;
				cout<<"-----------------------------------------------\n"<<endl;
				for(int i=0; i<creados; i++){
					if(A[i]!=NULL){
						cout<<"Autonoma["<<i<<"]"<<endl;
						A[i]->displayTerminal();
					}
				}
				cout<<"-----------------------------------------------"<<endl;
				}
				break;
			case 10:
				return 0;
		}
	
	}
	 
}

int menu(){
	//system("clear");
	int opcion;
	cout<<"\nPor favor elija una opcion."<<endl;
	cout<<"\t1 - Crear nuevo Automata."<<endl;
	cout<<"\t2 - Unir dos Automatas."<<endl;
	cout<<"\t3 - Concatenar dos Automatas."<<endl;
	cout<<"\t4 - Crear Cerradura Positiva a un Automata."<<endl;
	cout<<"\t5 - Crear Cerradura Estrella a un Automata."<<endl;
	cout<<"\t6 - Crear Cerradura Interrogacion a un Automata."<<endl;
	cout<<"\t7 - Evaluar cadena en Automata."<<endl;
	cout<<"\t8 - Ver la forma tabular del Automata AFN a AFD."<<endl;
	cout<<"\t9 - Ver listado de mis Automatas."<<endl;
	cout<<"\t10 - Salir del programa."<<endl<<endl;
	cout<<"\tOpcion : ";cin>>opcion;
	return opcion;
}






