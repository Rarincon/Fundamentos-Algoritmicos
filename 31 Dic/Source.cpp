//Nairobi, Denver, Tokio y Rio acaban de terminar el atraco a la Fabrica Nacional de Moneda y Timbre. Han guardado los billetes en bolsas con diferentes cantidades de fajos y por lo tanto 
//distintos pesos. Deciden repartirse el botin entre los 4 sin contar billetes, es decir, por peso (el peso total del botin sera divisble entre 4, y no dara decimales periodicos). 
//Para ello deciden pedirle al profesor que les ayude a repartirlo y este utiliza el siguiente algoritmo para realizar la tarea.

//Siendo Nairobi = 1
//Siendo Denver = 2
//Siendo Tokio = 3
//Siendo Rio = 4

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAX = 20;

//Podas:
//Si la suma del botin de una de las personas se pasa del peso medio establecido no seguira por esa rama
//Llevar en una variable float el valor del peso minimo de las bolsas del problema, si llevamos ya acumulado un peso que sumado a ese minimo va hacer que nos pasemos siempre del peso
//al que debe llegar cada persona no debemos continuar por dicha rama ya que no se llegará a ninguna solucion.
//La ultima forma de poda es una derivacion de la anterior, si llevamos un array lleno con el minimo peso de las cajas que nos quedan por entregar se realizara una poda mas exacta en principio

void conseguirCantidad(const vector <float>& arrayPesos, float peso, int arraySol[MAX],int cont, int k, float suma1, float suma2, float suma3, float suma4, bool& exito) {
	if (!exito && (suma1 + arrayPesos[k]) <= peso) {
		arraySol[k] = 1;
		suma1 += arrayPesos[k];
		if (suma1 + suma2 + suma3+ suma4 == 4 * peso)
			exito = true;
		else if (k < cont - 1)
			conseguirCantidad(arrayPesos, peso, arraySol, cont, k + 1, suma1, suma2, suma3, suma4, exito);
		suma1 -= arrayPesos[k];
	}
	if (!exito && (suma2 + arrayPesos[k]) <= peso) {
		arraySol[k] = 2;
		suma2 += arrayPesos[k];
		if (suma1 + suma2 + suma3 + suma4 == 4 * peso)
			exito = true;
		else if (k < cont - 1)
			conseguirCantidad(arrayPesos, peso, arraySol, cont, k + 1, suma1, suma2, suma3, suma4, exito);
		suma2 -= arrayPesos[k];
	}
	if (!exito && (suma3 + arrayPesos[k]) <= peso) {
		arraySol[k] = 3;
		suma3 += arrayPesos[k];
		if (suma1 + suma2 + suma3 + suma4 == 4 * peso)
			exito = true;
		else if (k < cont - 1)
			conseguirCantidad(arrayPesos, peso, arraySol, cont, k + 1, suma1, suma2, suma3, suma4, exito);
		suma3 -= arrayPesos[k];
	}
	if (!exito && (suma4 + arrayPesos[k]) <= peso) {
		arraySol[k] = 4;
		suma4 += arrayPesos[k];
		if (suma1 + suma2 + suma3 + suma4 == 4 * peso)
			exito = true;
		else if (k < cont - 1)
			conseguirCantidad(arrayPesos, peso, arraySol, cont, k + 1, suma1, suma2, suma3, suma4, exito);
		suma4 -= arrayPesos[k];
	}
}


bool resolverProblema(const vector <float>& arrayPesos, int arraySol[MAX], int cont) { //El arraySol es de int, ya que dice de quien es la caja, no lleva decimales

	float peso = 0;
	for (int i = 0; i < cont; i++)
		peso += arrayPesos[i];

	bool exito = false;
	if(cont>=4)
		conseguirCantidad(arrayPesos, peso / 4, arraySol, cont, 0, 0, 0, 0, 0, exito);
	return exito;
}

void resuelveCaso() {
	//resuelve aqui tu caso
		//Lee los datos

	float num;
	int cont;
	vector<float> arrayPesos;
	cin >> cont;
	for (int i = 0; i < cont; i++) {
		cin >> num;
		arrayPesos.push_back(num);
	}
	bool b;
	int arraySol[MAX];
	//Calcula el resultado
	b = resolverProblema(arrayPesos, arraySol, cont);
	//Escribe el resultado
	if (b) {
		for (int i = 0; i < cont; i++) cout << arraySol[i] << " "; cout << endl;
	}
	else cout << "No se puede dividir" << endl;
}
int main() {
	// Para la entrada por fichero.
/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif*/
	unsigned int numCasos;
	std::cin >> numCasos;

	//Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif*/

	return 0;
}

/*
#include <fstream>
#include <iostream>
#include <time.h>

using namespace std;

const int MAX_CASOS = 50;
const int MAX_BOLSAS = 20;

typedef float tLista[MAX_CASOS][MAX_BOLSAS];

void crearCaso(tLista lista, int num) {
	float numRandom;
	//int acum = 0;
	for (int i = 0; i < MAX_BOLSAS; i++) {
		numRandom = rand();
		lista[num][i] = numRandom / 1000;
		//acum += lista[num][i];
	}
	//if (acum % 4)
}

void crearCasos(tLista lista) {
	for (int i = 0; i < MAX_CASOS; i++) {
		crearCaso(lista, i);
	}
}

void guardar(tLista lista) {
	ofstream fichero;
	fichero.open("casos.txt");
	if (fichero.is_open()) {
		fichero << MAX_CASOS << endl;
		for (int i = 0; i < MAX_CASOS; i++) {
			fichero << MAX_BOLSAS << " ";
			for (int j = 0; j < MAX_BOLSAS; j++) {
				fichero << lista[i][j] << " ";
			}
			fichero << endl;
		}
		fichero.close();
	}
}

int main() {
	tLista lista;
	srand(time(NULL));
	crearCasos(lista);
	guardar(lista);
	return 0;
}*/


void conseguirCantidad(const vector <float>& arrayPesos, vector<bool>& pesos, float peso, int arraySol[MAX], int cont, int k, float suma1, float suma2, float suma3, float suma4, float min, bool& exito) {
	float aux = min;
	bool done = false;
	if (!exito && (suma1 + min) <= peso) {
		arraySol[k] = 1;
		suma1 += min;
		if (suma1 + suma2 + suma3 + suma4 == 4 * peso)
			exito = true;
		else if (k < cont - 1) {
			for (int i = 0; i < pesos.size() && done == false; i++) {
				if (arrayPesos[i] == min && pesos[i] == true) {
					pesos[i] = false;
					done = true;
				}
				conseguirCantidad(arrayPesos, pesos, peso, arraySol, cont, k + 1, suma1, suma2, suma3, suma4, nuevoMin(arrayPesos, min, pesos), exito);
			}
			suma1 -= aux;
			for (int i = pesos.size() - 1; i > 0 && done == true; i--) {
				if (arrayPesos[i] == min && pesos[i] == false) {
					pesos[i] = true;
					done = false;
				}
			}
		}
	}
	if (!exito && (suma2 + min) <= peso) {
		arraySol[k] = 2;
		suma2 += min;
		if (suma1 + suma2 + suma3 + suma4 == 4 * peso)
			exito = true;
		else if (k < cont - 1) {
			for (int i = 0; i < pesos.size() && done == false; i++) {
				if (arrayPesos[i] == min && pesos[i] == true) {
					pesos[i] = false;
					done = true;
				}
			}
			conseguirCantidad(arrayPesos, pesos, peso, arraySol, cont, k + 1, suma1, suma2, suma3, suma4, nuevoMin(arrayPesos, min, pesos), exito);
		}
		suma2 -= aux;
		for (int i = pesos.size() - 1; i > 0 && done == true; i--) {
			if (arrayPesos[i] == min && pesos[i] == false) {
				pesos[i] = true;
				done = false;
			}
		}
	}
	if (!exito && (suma3 + min) <= peso) {
		arraySol[k] = 3;
		suma3 += min;
		if (suma1 + suma2 + suma3 + suma4 == 4 * peso)
			exito = true;
		else if (k < cont - 1) {
			for (int i = 0; i < pesos.size() && done == false; i++) {
				if (arrayPesos[i] == min && pesos[i] == true) {
					pesos[i] = false;
					done = true;
				}
			}
			conseguirCantidad(arrayPesos, pesos, peso, arraySol, cont, k + 1, suma1, suma2, suma3, suma4, nuevoMin(arrayPesos, min, pesos), exito);
		}
		suma3 -= aux;
		for (int i = pesos.size() - 1; i > 0 && done == true; i--) {
			if (arrayPesos[i] == min && pesos[i] == false) {
				pesos[i] = true;
				done = false;
			}
		}
	}
	if (!exito && (suma4 + min) <= peso) {
		arraySol[k] = 4;
		suma4 += min;
		if (suma1 + suma2 + suma3 + suma4 == 4 * peso)
			exito = true;
		else if (k < cont - 1) {
			for (int i = 0; i < pesos.size() && done == false; i++) {
				if (arrayPesos[i] == min && pesos[i] == true) {
					pesos[i] = false;
					done = true;
				}
			}
			conseguirCantidad(arrayPesos, pesos, peso, arraySol, cont, k + 1, suma1, suma2, suma3, suma4, nuevoMin(arrayPesos, min, pesos), exito);
		}
		suma4 -= aux;
		for (int i = pesos.size() - 1; i > 0 && done == true; i--) {
			if (arrayPesos[i] == min && pesos[i] == false) {
				pesos[i] = true;
				done = false;
			}
		}
	}
	
}