#include <iostream>

using namespace std;

int main() {
	int piso, aux, cant;
	cin >> piso;
	while (piso > -1) {
		cant = 0;
		cin >> aux;
		while (aux > -1) {
			if (piso < aux)
				cant = cant + (aux - piso);
			else
				cant = cant + (piso - aux);
			piso = aux;
			cin >> aux;
		}
		cout << cant << endl;
		cin >> piso;
	}
	return 0;
}