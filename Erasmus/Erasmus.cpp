#include <iostream>
using namespace std;

typedef int tJugadores[1000];

int main()
{
	tJugadores jugador;
	int cont;
	cin >> cont;
	while (cont != 0)
	{
		for (int i = 0; i < cont; i++)
			cin >> jugador[i];
		int n=0;
		for (int i = 0; i < cont; i++)
			n = n + jugador[i];

		cout << n << endl;
	}

	return 0;
}