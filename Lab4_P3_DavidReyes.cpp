#include <iostream>
using namespace std;
void menu() {
	int opcion;
	bool princl = true;
	while (princl) {
		cout << "1.Ejercicio 1\n2.Ejericicio 2\n0.Salir";
		cin >> opcion;
		switch (opcion) {
		case 1:break;
		case 2:
			break;
		case 0:
			princl = false;
			break;
		default:
			cout << "Opcion no valida";
			break;
		}
	}
}
int main()
{
	menu();
	return 0;
}