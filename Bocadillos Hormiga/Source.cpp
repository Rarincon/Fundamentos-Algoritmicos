#include <iostream>
using namespace std;

int main() {
	int cant, ini, fin,aux,n, pos;

	cin >> cant;
	while (cant > 0) {
		cin >> ini;
		pos = 0;
		aux = ini;
		n = 1;
		while (n < cant-1){
			cin >> fin;
			if (fin > ini) {
				pos = n + 1;
				ini = fin;
			}
			n++;
		}
		cin >> fin;
		if (aux >= fin)
			cout << "SI" << " "<<pos << endl;
		else
			cout << "NO" << endl;
		cin >> cant;
	}

	return 0;
}