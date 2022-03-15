#include "Lista.h"

Lista::Lista() {

	ptrPrimero = ptrUltimo = ptrAux = NULL;
}
Lista::~Lista() {
	
	//delete ptrPrimero;
	//ptrPrimero = NULL;
	//
	//delete ptrUltimo;
	//ptrUltimo = NULL;

	//delete ptrAux;
	//ptrAux = NULL;
}

Nodo* Lista::NuevoNodo(string pCaracter,string numTel) {
	return new Nodo(pCaracter, numTel);
}

void Lista::insertar(string palabra, string numTel) {

	 palabra = coverMin(palabra);

	Nodo* ptrTemp = NULL;
	if (ptrPrimero == NULL){//No existe nodo
		insertInicio(palabra,numTel);
	}
	else{
		if (int(palabra[0]) < int(ptrPrimero->getDate())) { //
			insertInicio(palabra,numTel);
			return;
		}else if (int(palabra[0]) > int(ptrUltimo->getDate())) {//el dato es mayor al ult, se inserta al final
			insertFinal(palabra, numTel);
		}else{	
			ptrAux = ptrTemp = ptrPrimero;
			while (ptrAux != NULL){	
				if (int(palabra[0]) == int(ptrAux->getDate())) {
					ptrAux->arbol->ptrRaiz = ptrAux->arbol->insertar(ptrAux->arbol->ptrRaiz, palabra, numTel);
					break;
				}
				else if (int(palabra[0]) > int(ptrAux->getDate())) {
					ptrTemp = ptrAux;
					ptrAux = ptrAux->ptrNext;
				}
				else{
					insertarXLugar(palabra, ptrTemp , ptrAux, numTel);
					break;
				}
			}
			cout << palabra << " agregada exitosamente" << endl;
		}
	}
	
	ptrAux = NULL;
	ptrTemp = NULL;
}

void Lista::insertarXLugar(string pCaract,Nodo* ptrAnterior,Nodo* ptrSig, string numTel){

	Nodo* ptrTemp = NuevoNodo(pCaract, numTel);
	Nodo* ptrA= ptrSig;

	ptrAnterior->ptrNext = ptrTemp;
	ptrTemp->ptrNext = ptrA;
}

void Lista::insertInicio(string pCaract,string numTel) {
	this->ptrAux = NuevoNodo(pCaract,numTel);

	ptrAux->ptrAnt = NULL;
	ptrAux->ptrNext = ptrPrimero;//esto sirve cuando hay nodo y cuando no hay

	if (ptrPrimero != NULL) {//existen nodos
		ptrPrimero->ptrAnt = ptrAux;
		ptrPrimero = ptrAux;
	}
	else //Lista vacia - inserto el primer nodo
		ptrPrimero = ptrUltimo = ptrAux;

	ptrAux = NULL;
}

void Lista::insertFinal(string pCaract,string numberTel) {
	this->ptrAux = NuevoNodo(pCaract, numberTel);
	ptrAux->ptrNext = NULL;
	ptrAux->ptrAnt = ptrUltimo; //ver esto

	if (ptrUltimo != NULL) {//existen nodos
		ptrUltimo->ptrNext = ptrAux;
		ptrUltimo = ptrAux;
	}
	else //Lista vacia - inserto el primer nodo
		ptrPrimero = ptrUltimo = ptrAux;

	ptrAux = NULL;
}

void Lista::mostrar() {
	ptrAux = ptrPrimero;
	if (ptrAux != NULL) {
		while (ptrAux != NULL) {
			//cout << "NODO: #" << i << " -> Valor: " << ptrAux->getDate() << endl;
			cout <<"Letra: "<< ptrAux->getDate() << endl;
			ptrAux->arbol->mostrarA(ptrAux->arbol->ptrRaiz);
			cout << "-------------------------------------" << endl;
			ptrAux = ptrAux->ptrNext;//con esto avanzo
		}
	}
	else
		cout << "Lista vacia\n";
	cout << "\n";
	ptrAux = NULL;

}

//int Lista::positionAscii(char caracter) {
//	return caracter;
//}

void Lista::eliminar() {
	Nodo* ptrAnt = NULL;
	ptrAux = ptrAnt = this->ptrPrimero;
	string palabra;
	cout << "Ingrese el nombre: "; cin >> palabra;
	palabra = coverMin(palabra);


	if (ptrAux != NULL){
		while (ptrAux != NULL){
			if (palabra[0] == ptrAux->getDate()){
				ptrAux->arbol->ptrRaiz = ptrAux->arbol->eliminar(ptrAux->arbol->ptrRaiz, palabra);// eliminar arbol
				if (ptrAux->arbol->ptrRaiz == NULL){

					delete ptrAux->arbol;
					ptrAux->arbol = NULL;
					if (ptrAux == ptrPrimero){ // Eliminar al inicio
						eliminarInicio();
					}
					else if (ptrAux == ptrUltimo) {// Eliminar final
						eliminarFinal();
					}else{ // medio
						ptrAnt->ptrNext = ptrAux->ptrNext;
						ptrAux->ptrNext = NULL;
						ptrAux->ptrAnt = NULL;
						delete ptrAux;
						ptrAux = NULL;	
					}
				}
				return;
			}
			ptrAnt = ptrAux;
			ptrAux = ptrAux->ptrNext;
		}
	}
	else {
		cout << "Agenda vacia"<< endl;
	}
	ptrAux = NULL;
}

void Lista::eliminarInicio(){
	//string response = "Se ha eliminado el contacto: ";

	if (ptrPrimero != NULL) {
		ptrAux = ptrPrimero;

		//response += to_string(ptrAux->getDate());
		if (ptrAux == ptrUltimo)
			ptrUltimo = ptrPrimero = NULL;
		else {
			ptrPrimero = ptrPrimero->ptrNext;//esto puede ir en la linea 103
			ptrPrimero->ptrAnt = NULL;
			ptrAux->ptrNext =NULL;
		}

		delete ptrAux;
		ptrAux = NULL;
	}
	//else
		//response = "Lista vacia";

	//cout << response << endl;

}

void Lista::eliminarFinal(){
	//string response = "Se ha eliminado el contacto: ";

	if (ptrUltimo != NULL) {
		ptrAux = ptrUltimo;

		//response += to_string(ptrAux->getDate());

		if (ptrPrimero != ptrUltimo) {
			ptrUltimo = ptrUltimo->ptrAnt;
			ptrUltimo->ptrNext = NULL;
		}
		else {
			ptrPrimero = ptrUltimo = NULL;

		}

		delete ptrAux;
		ptrAux = NULL;
	}
	//else
		//response = "Lista vacia\n";

	//cout << response << endl;
}

string Lista::coverMin(string pDate){
	for (short i = 0; i < pDate.length(); i++) {
		pDate[i] = tolower(pDate[i]);
	}
	return pDate;
}

