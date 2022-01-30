#include <stdio.h>
#include <iostream>
#include <fstream>
#include<algorithm>
using namespace std;

const int MAX = 50;


//Implementa el algoritmo de vuelta atras. Explica los marcadores utilizados

//Usamos un array de marcado, que indica si un Grupo/artista ya se le ha asginado un posicion en el orden de actuaciones
//Tambien usamos un marcaje "indirecto" con la variable suma, pues va comprobando diversas sumas de las diferentes ramas del arbol recursivo


/*int contarMaxRestante(int maximaRecaudacion[MAX], bool marcado[MAX], int n) {
	int maxRestante = 0;
	for (int i = 0; i < n; i++)
		if (!marcado[i]) maxRestante += maximaRecaudacion[i];
	return maxRestante;
}*/

void recursion(int donaciones[MAX][MAX], int vetos[MAX][MAX], int maximaRecaudacion[MAX], int& suma, int& maximo, int k, bool& exito, int n, bool marcado[MAX], int j) {
	for (int i = 0; i < n; i++) {
		if (!marcado[i] && vetos[i][j] == 1 && suma + maximaRecaudacion[j*k] > maximo) { //La ultima condicion no es correcta, pues no esta bien elaborada y nos da errores
			suma += donaciones[i][k];
			if (k == n - 1) {
				exito = true;
				if (suma > maximo)maximo = suma;
			}
			else {
				marcado[i] = true;
				recursion(donaciones, vetos, maximaRecaudacion, suma, maximo, k + 1, exito, n, marcado, i);
				marcado[i] = false;
			}
			suma -= donaciones[i][k];
		}
	}
}

void inicioRecursion(int donaciones[MAX][MAX], int vetos[MAX][MAX], int maximaRecaudacion[MAX], int& suma, int& maximo, int k, bool& exito, int n) {
	bool marcado[MAX];
	//Inicializa el array
	for (int i = 0; i < n; i++)
		marcado[i] = false;

	for (int i = 0; i < n; i++) {
		marcado[i] = true;
		suma += donaciones[i][k];
		recursion(donaciones, vetos, maximaRecaudacion, suma, maximo, k + 1, exito, n, marcado, i);
		suma -= donaciones[i][k];
		marcado[i] = false;
	}
}

/*int calculaMaximoIngreso(int donaciones[MAX][MAX], int n) {
	int max = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (max < donaciones[i][j]) max = donaciones[i][j];
	return max;
}*/
void rellenarArrayRecaudacionesMaximas(int maximaRecaudacion[MAX], int donaciones[MAX][MAX], int n) {
	//Inicializa el array
	for (int i = 0; i < n; i++) maximaRecaudacion[i] = 0;

	//Rellena el array
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (maximaRecaudacion[i] < donaciones[i][j]) maximaRecaudacion[i] = donaciones[i][j];

	//Crea el array definitivo
	int acumulador = 0, aux;
	for (int i = n - 1; i >= 0; i--) {
		aux = maximaRecaudacion[i];
		maximaRecaudacion[i] = acumulador;
		acumulador += aux;
	}
}

//Plantea dos posibles funciones de poda de optimalidad, razona sobre cual de ellas es mejor
//e implementala

//1) Si el maximo valor que hemos obtenido como solucion es mayor que lo que llevamos acumulado +(el numero de artista que quedan para rellenar
// el planning * el numero maximo ingreso ingreso del ejemplo) no merece la pena seguir por ese camino. (Necesario un int con la donacion maxima)
//2) Si el maximo valor que hemos obtenido como solucion es mayor que lo que llevamos acumulado +el maximo ingreso que podemos obtener de
//los artistas que faltan por rellenar el planning, no merece la pena seguir por es camino. (Necesarios un array con las maximas donaciones que
//podamos obtener en funcion de la k por la que vayamos



void resuelveCaso()
{
	//Rellena los arrays
	int n; //n numero de artistas
	cin >> n;
	int donaciones[MAX][MAX]; //Leemos las donaciones esperadas

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; ++j)
		{
			cin >> donaciones[i][j];
		}

	int vetos[MAX][MAX]; //leemos los vetos de los artistas
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; ++j)
		{
			cin >> vetos[i][j];
		}

	//Inicializa los argumentos que necesita el algoritmo
	int maximaRecaudacion[MAX];
	int K = 0, suma = 0, maximo = 0;
	bool exito = false;
	rellenarArrayRecaudacionesMaximas(maximaRecaudacion, donaciones, n);

	//Llama al algoritmo de vuelta atras
	inicioRecursion(donaciones, vetos, maximaRecaudacion, suma, maximo, K, exito, n);

	//Escribe en la salida el resultado.
	if (exito) cout << maximo << endl;
	else cout << "NEGOCIA CON LOS ARTISTAS" << endl;
}

int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();
	return 0;

}

//COSTES:
//Tamaño de datos de entrada n, siendo n el numero de grupos/artistas que hay.
//Coste de la funcion resuelveCaso es O(n^2), siendo n el numero de grupos/artistas que hay.
//Coste de la funcion rellenarArrayRecaudacionesMaximas es de O(n), siendo n el numero de grupos/artistas que hay.
//Coste de la funcion inicioRecursion es de O(n), siendo n el numero de grupos/artistas que hay.
//Coste de la funcion recursion es de O(n), siendo n el numero de grupos/artistas que hay :
		//T(n){no hay caso base
		//	  {c1+T(n-1) resto de los casos

		// El coste final es de O(n^2)

//CONDICIONES
//1)Un array de marcado, que indica si a un Artista ya se le ha asigando una posicion de el orden en el que van a actuar,sirve para mejorar el coste
//2)La matriz de vetos tambien sirve de poda, pues tras haber asignado a un Artista, comprueba si otro artista esta dispuesto a tocar despues del primero
//3)Un array con los mejores valores de las donaciones en funcion del orden,que se encarga de calcular si por la rama que vamos se puede llegar a obtener
//una mejor donacion de la que ya tenemos altualme, en el caso de que haya una





//////////////////////////////////////////////////////// PRUEBAS, NO  VALEN
/*
#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 20;


void recursion(int donaciones[MAX][MAX], int vetos[MAX][MAX], int& suma, int& maximo, int k, bool& exito, int n, int marcado[MAX], int j) {
	for (int i = 0; i < n; i++) {
		if (!marcado[i] && vetos[i][j] == 1) {
			suma += donaciones[i][k];
			if (k == n - 1) {
				exito = true;
				if (suma > maximo)maximo = suma;
			}
			else {
				marcado[i] = true;
				recursion(donaciones, vetos, suma, maximo, k + 1, exito, n, marcado, i);
				marcado[i] = false;
			}
			suma -= donaciones[i][k];
		}
	}
}

void recursion2(int donaciones[MAX][MAX], int vetos[MAX][MAX], int& suma, int& maximo, int k, bool& exito, int n) {
	int marcado[MAX];
	for (int i = 0; i < n; i++)
		marcado[i] = false;
	for (int i = 0; i < n; i++) {
		marcado[i] = true;
		suma += donaciones[i][k];
		recursion(donaciones, vetos, suma, maximo, k + 1, exito, n, marcado, i);
		suma -= donaciones[i][k];
		marcado[i] = false;
	}
}


/*void recursion(int donaciones[MAX][MAX], int vetos[MAX][MAX], int& suma, int& maximo, int k, bool &exito, int n, int marcado[MAX]) {
	for (int i = 0; i < n; i++) {
		if (vetos[i][k] == 1&& !marcado[k]) {
			suma += donaciones[i][k];
			marcado[i] = true;
			if (k == n-1) {
				exito = true;
				if (suma > maximo)maximo = suma;
			}
			else
				recursion(donaciones, vetos, suma, maximo, k + 1, exito, n, marcado);
			suma -= donaciones[i][k];
			marcado[i] = false;
		}
	}
}

void recursion2(int donaciones[MAX][MAX], int vetos[MAX][MAX], int& suma, int& maximo,int k, bool exito, int n) {
	int marcado[MAX];
	for (int i = 0; i < n; i++)
		marcado[i] = false;
	for (int i = 0; i < n; i++) {
		marcado[i] = true;
		suma += donaciones[i][k];
		recursion(donaciones, vetos, suma, maximo, k + 1, exito, n, marcado);
		suma -= donaciones[i][k];
		marcado[i] = false;
	}
}

void resuelveCaso() {
	int n, K,suma,maximo;
	bool exito;
	int donaciones[MAX][MAX];
	int vetos[MAX][MAX];
	
	K = 0;
	exito = false;
	suma = 0;
	maximo=0;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin>>donaciones[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> vetos[i][j];

	recursion2(donaciones, vetos, suma, maximo,K,exito, n);
	if (exito)cout << maximo << endl;
	else cout << "NEGOCIA CON LOS ARTISTAS" << endl;
	
	
	
	
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado
}

int main() {
	// Para la entrada por fichero.
/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}


/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}*/