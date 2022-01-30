#include<iostream>
#include<string>

using namespace std;

int main() {
	int cant, ini,fin, n;
	string cadena,aux, pos;
	bool ok;
	getline(cin,cadena);
	cin >> cant;
	while (cant > 0) {
		n = 0;
		while (n < cant) {
			ok = true;
			cin >> ini;
			cin >> fin;
			aux = char(cadena[ini]);
			for (int i = ini + 1; i < fin + 1 && ok; i++) {
				pos = char(cadena[i]);
				if (pos != aux)
					ok = false;

			}
			if (ok)
				cout << "SI" << endl;
			else
				cout << "NO" << endl;
			n++;
		}
		getline(cin,cadena);
		cin >> cant;
	}

	return 0;
}