#pragma once
#include<iostream>
#include<string>
#include "Lista.h"
using namespace std;

class NodoA
{
private:
	string number;
	string nombre;


public:
	NodoA();
	NodoA(string,string);
	~NodoA();
	NodoA* ptrIzq;
	NodoA* ptrDer;
	void setNumber(string);
	string getNumber();

	void setNombre(string);
	string getNombre();

};

