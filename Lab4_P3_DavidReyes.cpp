#include <iostream>
using namespace std;
int factorial(int num, int result) {//metodo para sacar factorial
	;
	if (num == 0) {
		result *= 1;
		return result;
	}
	else {
		result *= num;
		return factorial(num - 1, result);
	}
}
int num_repe(char letra, string prin) {
	int result=0;
	for (int i = 0; i < prin.length();i++) {
		if (letra==prin[i]) {
			result++;
		}
	}
	return result;
}
//metodo para sacar numero de repes
void menu() {
	string palabra;//palabra principal
	int opcion,total,sumfactorial,contletras;
	
	bool princl = true,encontrada,flag=true;
	while (princl) {
		char repetidas[6]{};
		sumfactorial=1;
		total = 0;
		cout << "1.Ejercicio 1\n2.Ejericicio 2\n0.Salir"<<endl;
		cin >> opcion;
		switch (opcion) {
		case 1:
			cout << "Ingrese palabra para calcular Permutaciones"<<endl;
			cin >> palabra;
			while (palabra.length()<6) {
				cout << "Tiene que ser mas grande la palabra" << endl;
				cout << "Ingrese palabra para calcular Permutaciones" << endl;
				cin >> palabra;
			}
			for (int k = 0; k < palabra.length(); k++) {//for para validar mayusculas
				if (palabra[k]<65&&palabra[k]>90) {
					flag = false;
				}
			}
			while (flag==false) {
				cout << "Solo mayusculas" << endl;
				cout << "Ingrese palabra para calcular Permutaciones" << endl;
				cin >> palabra;
				for (int k = 0; k < palabra.length(); k++) {//for para validar mayusculas
					if (palabra[k] < 65 && palabra[k]>90) {
						flag = false;
					}
				}
			}
			cout << "Letras que se repiten: " << endl;
			total =factorial(palabra.length(),1);
			for (int i = 0; i < palabra.length(); i++)//for para tomar 1 caracter
			{
				encontrada = false;
				for (int j = i+1; j < palabra.length(); j++) {
					if (palabra[i]==palabra[j]) {
						encontrada = true;
						repetidas[i] = palabra[i];
					}
				}
				contletras = 0;
				for (size_t t = 0; t < 6; t++)
				{
					for (size_t g = t + 1; g < 6; g++)
					{
						if (repetidas[t] == repetidas[g]) {
							contletras++;
						}
					}

				}
				if (encontrada == true&&contletras!=2) {
					cout << palabra[i] << ": " << num_repe(palabra[i], palabra) << " Veces" << endl;
					sumfactorial *= factorial(num_repe(palabra[i], palabra), 1); 
				}
			}
			total /= sumfactorial;
			cout << "Numero de permutaciones de la palabra " << palabra <<": "<<total<<endl;
			
			break;
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