#include <iostream>

using namespace std;

int main()
{
	int cont;
	do {
		//cout << "\nIntroduce un numero entre el 0 y el 5, incluyendolos" << endl;
		cin >> cont;
	} while (cont < 0 || cont >5);

	for (int i = 0; i < cont; i++)
		cout << "Hola mundo." << endl;
	return 0;
}