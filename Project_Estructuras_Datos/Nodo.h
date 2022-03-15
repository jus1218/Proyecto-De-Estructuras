#pragma once
#include<iostream>
#include "Lista.h"
#include "Arbol.h"

class Nodo;
class Lista;
class Arbol;

using namespace std;
class Nodo
{
private:
	char date;

public:
	Nodo* ptrNext;
	Nodo* ptrAnt;
	Nodo();
	Nodo(string,string);
	~Nodo();
	void setDate(char);
	char getDate();
	Arbol* arbol;


};
