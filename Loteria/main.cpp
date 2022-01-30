#include <iostream>
using namespace std;

typedef int tArray[50];
typedef struct
{
	int cont = 0;
	int salida = 0;
	tArray num;
}tList;

typedef tList arraylista[50];
typedef struct
{
	int cont = 0;
	arraylista lista;
}tLista;

int main()
{
	tLista lista;
	cin >> lista.cont;
	for (int j = 0; j < lista.cont; j++) {
		cin >> lista.lista[j].cont;
		for (int i = 0; i < lista.lista[j].cont; i++) {
		cin >> lista.lista[j].num[i];
		if (lista.lista[j].num[i] % 2 == 0)
			lista.lista[j].salida++;
		}
	}
	for (int j = 0; j < lista.cont; j++) {
		cout << lista.lista[j].salida<<endl;
	}
	return 0;
}