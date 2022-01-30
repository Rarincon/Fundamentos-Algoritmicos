#include <iostream>

using namespace std;

int main() {
	int muros, muro,saltos,arriba, abajo, salto,aux;
	cin >> muros;
	int n = 0;
	
	while (n < muros) {
		cin >> saltos;
		abajo = 0;
		arriba = 0;
		cin >> aux;
		for (int i = 1; i < saltos; i++) {
			cin >> salto;
			if (aux < salto)
				arriba++;
			else if (aux > salto)
				abajo++;
			aux = salto;
		}
		cout << arriba << " " << abajo << endl;
		n++;
	}
	return 0;
}
