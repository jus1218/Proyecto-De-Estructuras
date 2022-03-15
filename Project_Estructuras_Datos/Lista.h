#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "Nodo.h"

class Lista;
class Nodo;


using namespace std;
class Lista
{
private:
	Nodo* ptrAux;
	Nodo* ptrPrimero;
	Nodo* ptrUltimo;
	//Metodo
	Nodo* NuevoNodo(string,string);
public:
	Lista();
	~Lista();

	//Metodos
	void insertar(string,string);
	void insertarXLugar(string,Nodo*, Nodo*,string);
	void insertInicio(string,string);
	void insertFinal(string,string);
	void mostrar();
	void eliminar();
	void eliminarInicio();
	void eliminarFinal();
	string coverMin(string);
	/*int positionAscii(char);*/

};

