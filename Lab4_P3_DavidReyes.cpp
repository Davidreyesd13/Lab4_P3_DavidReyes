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
	int result = 0;
	for (int i = 0; i < prin.length(); i++) {
		if (letra == prin[i]) {
			result++;
		}
	}
	return result;
}
//metodo para sacar numero de repes
string buscar_secuencia(string principal) {//metodo para conseguir la secuencia
	int n = principal.size();
	int max_len = 0, start = 0;
	for (int i = 0; i < n; i++) {
		int j = i;
		while (j < n && principal[j] == principal[i]) {
			j++;
		}
		if (j - i > max_len) {
			max_len = j - i;
			start = i;
		}
	}
	return principal.substr(start, max_len);
}
void menu() {
	string palabra;//palabra principal
	int opcion, totalp, sumfactorial, contletras,a,c,g,t;//variables generales
	float ap, cp, gp, tp,total;//variables de porcentajes
	bool princl = true, encontrada, flag = true;
	while (princl) {
		totalp = 0;
		char repetidas[6]{};
		sumfactorial = 1;
		total = 0;
		cout << "1.Ejercicio 1\n2.Ejericicio 2\n0.Salir" << endl;
		cin >> opcion;
		switch (opcion) {
		case 1:
			cout << "Ingrese palabra para calcular Permutaciones" << endl;
			cin >> palabra;
			while (palabra.length() < 6) {
				cout << "Tiene que ser mas grande la palabra" << endl;
				cout << "Ingrese palabra para calcular Permutaciones" << endl;
				cin >> palabra;
			}
			for (int k = 0; k < palabra.length(); k++) {//for para validar mayusculas
				if (palabra[k] < 65 && palabra[k]>90) {
					flag = false;
				}
			}
			while (flag == false) {
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
			total = factorial(palabra.length(), 1);
			for (int i = 0; i < palabra.length(); i++)//for para tomar 1 caracter
			{
				encontrada = false;
				for (int j = i + 1; j < palabra.length(); j++) {
					if (palabra[i] == palabra[j]) {
						encontrada = true;
						repetidas[i] = palabra[i];//AGREGA AL ARREGLO CHAR
					}
				}
				contletras = 0;
				for (size_t m = 0; m < 6; m++)//FOR PARA VALIDAR QUE NO SE REPITA LA IMPRESION NI SE REPITA UN SEGUNDO FACTORIAL
				{
					for (size_t n = m + 1; n < 6; n++)
					{
						if (repetidas[m] == repetidas[n]) {
							contletras++;
						}
					}

				}
				if (encontrada == true && contletras != 2) {
					cout << palabra[i] << ": " << num_repe(palabra[i], palabra) << " Veces" << endl;
					sumfactorial *= factorial(num_repe(palabra[i], palabra), 1);//acumula valores
				}
			}
			total /= sumfactorial;
			cout << "Numero de permutaciones de la palabra " << palabra << ": " << total << endl;
			break;
		case 2:
			cout << "Ingrese una cadena de ADN: ";
			cin >> palabra;
			for (int k = 0; k < palabra.length(); k++) {//for para validar mayusculas
				if (palabra[k] == 65 && palabra[k]==67&& palabra[k] == 71&& palabra[k] == 84) {
					flag = false;
				}
			}
			while (flag == false) {
				cout << "Solo Letras ACGT" << endl;
				cout << "Ingrese una cadena de ADN: " << endl;
				cin >> palabra;
				for (int k = 0; k < palabra.length(); k++) {//for para validar mayusculas
					if (palabra[k] == 65 && palabra[k] == 67 && palabra[k] == 71 && palabra[k] == 84) {
						flag = false;
					}
				}
			}
			a = 0, c = 0, g = 0, t = 0;
			for (size_t i = 0; i < palabra.length(); i++)
			{
				switch (palabra[i]) {
				case 'A':
					a++;
					break;
				case 'C':
					c++;
					break;
				case 'G':
					g++;
					break;
				case 'T':
					t++;
					break;
				}
			}
			cout << "Analisis de la cadena de ADN: " << endl;
			cout << "- Numero total de nucleotidos: " << palabra.length()<<endl;
			cout << "- Numero de ocurrencias de cada nucleotido: " << endl;
			cout << "A: " << a << endl << "C: " << c <<endl<< "G: " << g <<endl<< "T: " << t << endl;
			cout << "- Porcentaje de cada nucleotido:"<<endl;
			totalp += a + c + g + t;
			ap = 0, cp = 0, gp = 0, tp = 0;
			//porcetanjes
			ap += (float)a / totalp * 100;
			cp += (float)c / totalp * 100;
			gp += (float)g / totalp * 100;
			tp += (float)t / totalp * 100;
			cout << "A: " << tp << "%" << endl << "C: " << cp << "%" << endl << "G: " << gp << "%" << endl << "T: " << tp<<"%" <<endl ;
			cout << "Secuencia mas larga: " << buscar_secuencia(palabra)<<endl;
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