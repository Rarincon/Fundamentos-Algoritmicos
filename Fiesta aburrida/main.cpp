#include <iostream>
using namespace std;

int main()
{
	int cont;
	string nombre;
	string basura;
	cin >> cont;
	for (int i = 0; i < cont; i++) {
		cin >> basura;
		cin >> nombre;
		cout << "Hola, " << nombre << "." << endl;
	}
	return 0;
}