#include "Arbol.h"
Arbol::Arbol() {
	ptrRaiz = ptrAux = NULL;
}

Arbol::~Arbol() {
	//delete ptrRaiz;
	//delete ptrAux;
	//ptrRaiz = ptrAux = NULL;
}

NodoA* Arbol::insertar(NodoA* ptrR, string nombre,string numTel) {
	if (ptrR != NULL) { //VERIFICA SI HAY UN NODO 
		if (sumatoria(nombre) < sumatoria(ptrR->getNombre())) { //VERIFICA SI ES MENOR AL DATO DEL NODO RAIZ
			ptrR->ptrIzq = insertar(ptrR->ptrIzq, nombre, numTel); //SI ES MENOR MANDA A POSICIONARLO A LA IZQUIERDA
		}
		else { //SI NO ES MENOR QUE EL NODO RAIZ
			if (sumatoria(nombre) > sumatoria(ptrR->getNombre())) { //VERIFICA QUE SEA MAYOR AL NODO RAIZ 
				ptrR->ptrDer = insertar(ptrR->ptrDer, nombre, numTel); //LO MANDA A POSICIONARLO A LA DERECHA
			}
			else {
				cout << "Usuario ya registrado" << endl; //SI NO ES MAYOR NI ES MENOR ES PORQUE ES IGUAL, Y SI ES IGUAL ES PORQUE YA ESTA
			}
		}

	}
	else {
		ptrAux = new NodoA(nombre,numTel);
		ptrR = ptrAux;
	}
	ptrAux = NULL;
	return ptrR;
}

void Arbol::mostrarA(NodoA* ptrR) {
	if (ptrR != NULL) {
		mostrarA(ptrR->ptrDer);
		cout <<"Nombre: "<< ptrR->getNombre()<<"  Telefono: " << ptrR->getNumber() << endl;
		mostrarA(ptrR->ptrIzq);
	}
}


NodoA* Arbol::eliminar(NodoA* ptrR, string pDato)
{
	NodoA* ptrTemp = NULL;
	if (ptrR != NULL)
	{
		if (sumatoria(pDato) < sumatoria(ptrR->getNombre()))
		{
			ptrR->ptrIzq = eliminar(ptrR->ptrIzq, pDato);
		}
		else
		{
			if (sumatoria(pDato) > sumatoria(ptrR->getNombre()))
			{
				ptrR->ptrDer = eliminar(ptrR->ptrDer, pDato);
			}
		}

		if (pDato == ptrR->getNombre())
		{
			if (ptrR->ptrIzq == NULL && ptrR->ptrDer == NULL)//1 hoja
			{
				cout << "\nSe ha eliminado el contacto: " << ptrR->getNombre() << endl;;
				delete ptrR;
				ptrR = NULL;
			}
			else
			{
				if (ptrR->ptrIzq != NULL && ptrR->ptrDer == NULL)//el nodo tiene 1 hijo izquierda
				{
					cout << "\nSe ha eliminado el contacto: " << ptrR->getNombre() << endl;;
					ptrAux = ptrR->ptrIzq;
					delete ptrR;
					return ptrAux;
				}
				else
				{
					if (ptrR->ptrIzq == NULL && ptrR->ptrDer != NULL)//el nodo tiene 1 hijo derecha
					{
						cout << "\nSe ha eliminado el contacto: " << ptrR->getNombre() << endl;;
						ptrAux = ptrR->ptrDer;
						delete ptrR;
						return ptrAux;

					}

				}

				ptrAux = ptrR->ptrIzq;//2 hijos
				if (ptrAux->ptrDer != NULL)
				{
					while (ptrAux->ptrDer != NULL)
					{
						ptrTemp = ptrAux;
						ptrAux = ptrAux->ptrDer;
					}

					cout << "\nSe ha eliminado el contacto: " << ptrR->getNombre() << endl;;
					ptrTemp->ptrDer = ptrAux->ptrIzq;
					ptrR->setNombre(ptrAux->getNombre());
				}
				else
				{
					cout << "\nSe ha eliminado el contacto: " << ptrR->getNombre() << endl;;
					ptrR->ptrIzq = ptrAux->ptrIzq;
					ptrR->setNombre(ptrAux->getNombre());
				}

				delete ptrAux;
				ptrTemp = ptrAux = NULL;
			}

		}




	}
	return ptrR;
}

int Arbol::sumatoria(string palabra){
	int valor = 0;
	for (short i = 0; i < palabra.length(); i++){
		valor += palabra[i];
	}
	return valor;
}
