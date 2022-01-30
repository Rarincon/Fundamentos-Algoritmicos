#include <iostream>
#include <string>
using namespace std;

/*
void sumdigits(int & sumd, int num) {
	while (num > 0) {
		sumd = sumd + num % 10;
		num = num / 10;
	}
}*/

int main() {
	int num,sumd,cont;
	string salida, aux;
	cin >> num;
	while (num > -1) {
		sumd = 0;
		cont = 0;
		salida = "";
		aux = to_string(num);
		if (num != 0) {
			while (num > 0) {
				sumd = sumd + num % 10;
				num = num / 10;
				cont++;
			}
			for (int i = 0; i < cont - 1; i++) {
				salida += aux[i];
				salida += " + ";
			}
			salida += aux[cont - 1];
		}
		else {
			sumd = 0;
			salida = to_string(sumd);
		}

		salida += " = ";
		
		cout << salida << sumd << endl;
		cin >> num;
	}
	return 0;
}


/*
int main() {
	int num,sumd,aux;
	char numero;
	string salida;
	cin >> numero;
	while (numero > -1) {
		sumd = 0;
		aux = numero;
		sumdigits(sumd, aux);
		
		/*for (int i = 0; i < sumd - 1; i++) {
			salida = numero[i] + " + ";
		}
	}

*/