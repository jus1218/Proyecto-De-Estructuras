#pragma once
#include<iostream>
#include "NodoA.h"
using namespace std;

class Arbol;
class NodoA;


class Arbol {

public:
	NodoA* ptrRaiz;
	NodoA* ptrAux;
	Arbol();
	~Arbol();
	NodoA* insertar(NodoA*, string,string);
	void mostrarA(NodoA*);
	NodoA* eliminar(NodoA*, string);
	int sumatoria(string);

};
