#include "Nodo.h"

Nodo::Nodo() {
	date = 0;
	ptrNext = NULL;
	ptrAnt = NULL;
	arbol = NULL;
}
Nodo::Nodo(string pDate,string numTel) {
	date = tolower(pDate[0]);
	ptrNext = NULL;
	ptrAnt = NULL;
	arbol = new  Arbol();



	arbol->ptrRaiz = arbol->insertar(arbol->ptrRaiz, pDate, numTel);

}
Nodo::~Nodo() {

	//delete ptrNext;
	//ptrNext = NULL;
	///*delete ptrAnt;*/
	//delete arbol;
	//arbol = NULL;
	/*ptrNext = ptrAnt = NULL;*/
}
void Nodo::setDate(char pDate) {
	this->date = pDate;
}

char Nodo::getDate() {
	return this->date;
}
