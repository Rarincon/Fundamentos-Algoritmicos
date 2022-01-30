#include <iostream>

using namespace std;

int main() {
	int n, cont, aux, aux1,aux2, aux3;
	bool mayor;
	cin >> n;
	while (n != 0) {
		cont = 0;
		mayor = false;
		cin >> aux;
		cin >> aux1;
		if (aux > aux1) mayor = true;
		aux3 = aux;
		for (int i = 0; i < n-2; i++) {
			cin >> aux2;
			if (aux1 > aux&& aux1 > aux2)
				cont++;
			aux = aux1;
			aux1 = aux2;
		}
		if (aux1 > aux&& aux1 > aux3)
			cont++;
		if (mayor && aux3 > aux1)
			cont++;

		cout << cont << endl;
		cin >> n;
	}
	
	return 0;
}