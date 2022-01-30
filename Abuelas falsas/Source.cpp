#include <iostream>
using namespace std;

int main() {
	int cant, numPer;
	string ini, otros;
	bool ok;
	cin >> cant;
	while (cant > 0) {
		ok = true;
		cin >> ini;
		cin >> numPer;
		if (numPer < 2){
			cin >> otros;
			ok = false;

		}
		else{
			for (int i = 0; i < numPer-1; i++) {
				cin >> otros;
				if (ini == otros)
					ok = false;
			}
			cin >> otros;
			if (ini != otros)
				ok = false;
		}
		if (ok)
			cout << "VERDADERA" << endl;
		else
			cout << "FALSA" << endl;

		cant--;
	}

	return 0;
}