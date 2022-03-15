#include "NodoA.h"
NodoA::NodoA()
{
	ptrIzq = NULL;
	ptrDer = NULL;
	number = " ";
	nombre = " ";
}

NodoA::NodoA(string nombre,string numTel)
{
	ptrIzq = NULL;
	ptrDer = NULL;
	this->nombre = nombre;
	this->number = numTel;
}

NodoA::~NodoA()
{
	//delete ptrIzq;
	//delete ptrDer;
	//ptrIzq = ptrDer = NULL;
}

void NodoA::setNumber(string dat)
{
	this->number = dat;
}

string NodoA::getNumber()
{
	return number;
}

void NodoA::setNombre(string name)
{
	this->nombre = name;
}

string NodoA::getNombre()
{
	return nombre;
}
