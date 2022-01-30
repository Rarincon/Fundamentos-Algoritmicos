#include <iostream>
using namespace std;
typedef int tArray[50];
typedef struct
{
	int cont=0;
	tArray num;
}tList;
 
typedef tList arraylista[50];
typedef struct
{
	int cont=0;
	arraylista lista;
}tLista;

int main()
{
	int j = 0;
	tLista lista;
	int cont;
	while ((cin>> cont)!=' ') {
		
		cin >> lista.lista[j].cont;
		for (int i = 0; i < lista.lista[lista.cont].cont;i++)
			cin >> lista.lista[lista.cont].num[i];
		lista.cont++;
		j++;
	}
	j = 0;
	while (j < lista.cont) {
		int max=0;
		for (int i = 1; i < lista.lista[j].cont; i++) {
			max= lista.lista[j].num[i-1];
			if (max < lista.lista[j].num[i])
				max = lista.lista[j].num[i];
		}
		cout << max;
		j++;
	}
	return 0;
}