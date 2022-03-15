#include"Lista.h"

int main() {

	Lista* objList = new Lista();
	short opc = 0;
	string palabra;
	string numTel;

	do
	{
		system("cls");
		cout << "\t< MENU AGENDA TELEFONICA >" << endl;
		cout << "Agregar.........1" << endl;
		cout << "Mostrar.........2" << endl;
		cout << "Eliminar........3" << endl;
		cout << "salir...........4" << endl;
		cin >> opc;

		cout << "\n\n";
		switch (opc)
		{
		case 1:
			cout << "Ingrese el nombre: "; cin >> palabra;
			cout << "Ingrese el numero de teleono: "; cin >> numTel;
			objList->insertar(palabra,numTel);
			break;
		case 2:
			objList->mostrar();
			break;
		case 3:
			objList->eliminar();
			break;
		case 4:
			cout << "Saliendo..." << endl;
			break;
		default:
			cout << "Opcion no existente" << endl;
			break;
		}
		system("pause");
		
	} while (opc != 4);


	/*objList*/
	delete objList;

	objList = NULL;
	cin.get();
	return 0;
}