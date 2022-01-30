#include <iostream>
#include <fstream>
using namespace std;

long long int power(int x, unsigned int y) {
	if (y == 0) return 1;
	else if (y % 2 == 0) return power(x, y / 2) * power(x, y / 2);
	else return x * power(x, y / 2) * power(x, y / 2);
}

int numDigitos(long long int num) {
	int n = 0;
	if (num == 0) n = 1;
	while (num > 0) {
		n++;
		num /= 10;
	}
	return n;
}

long long int recursion(const long long int& num) {
	long long int pot, aux, div,r;
	int numD;
	numD = numDigitos(num);
	if (numD == 1) {
		if (num == 1 || num == 0) r= 1;
		else r= num;
	}
	else {
		pot = power(10, numD - 1);
		div = num / pot;
		aux = div * pot;
		--div;
		if (div != 0)
			r= (div * power(9, numD - 1)) + recursion(num - aux);
		else
			r= recursion(aux - 1);
	}
	return r;
}

int main() {
	//resuelve aqui tu caso
	long long int num;

	//Lee los datos
	cin >> num;
	while (cin && num >= 0) {
		//Calcula y escribe el resultado
		cout << recursion(num) << endl;

		//Lee los datos
		cin >> num;
	}
	return 0;
}

//////////////////////////////////
//Coste del algoritmo

// Tamaño de datos=num
// T(num){ K si 0 <= num <= 9
//		 { J + L*P(d-1) + T(num-A) si num>=10

// P(d-1){ M si (d-1)=0
//	   	 { S*P((d-1)/2)*P((d-1)/2)

// K = es una constante de complejidad del coste en el caso directo, en nuestro ejercicio es 12)
// M, L, J, A = constantes de complejidad, no valen todas lo mismo, pueden ser distintas
// d = constante  de complejidad que indica cuantas cifras tiene num, va cambiando su valor
// P() = coste de la recursion de power

// El coste de P(d-1) es de O(log(d-1)) y este a su vez esta sumando al coste de T(num) que esde O(num)
// Por tanto el coste del algoritmo es de O(num), ya que O(log(d-1))<O(num)




///////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <fstream>
using namespace std;

long long int power(int x, unsigned int y) {
	if (y == 0) return 1;
	else if (y % 2 == 0) return power(x, y / 2) * power(x, y / 2);
	else return x * power(x, y / 2) * power(x, y / 2);
}

int numDigitos(long long int num) {
	int n = 0;
	if (num == 0) n = 1;
	while (num > 0) {
		n++;
		num /= 10;
	}
	return n;
}

long long int recursion(const long long int& num) {
	long long int pot, aux, div;
	int numD;
	numD = numDigitos(num);
	if (numD == 1) {
		if (num == 1 || num == 0) return 1;
		else return num;
	}
	else {
		pot = power(10, numD - 1);
		div = num / pot;
		aux = div * pot;
		--div;
		if (div != 0)
			return (div * power(9, numD - 1)) + recursion(num - aux);
		else
			return recursion(num - 1);
	}
}

int main() {//resuelve aqui tu caso
	long long int num;

	//Lee los datos
	cin >> num;
	while (cin && num >= 0) {
		//Calcula y escribe el resultado
		cout << recursion(num) << endl;

		//Lee los datos
		cin >> num;
	}
	return 0;
}
*/
///////////////////////////////////////////////////////////////////////




/*

#include <iostream>
#include <fstream>
//#include <math.h>
using namespace std;


int numD(long long int num) {
	long long int cont = 0;
	if (num == 0) return 1;
	while (num > 0 || num!=0) {
		cont++;
		num /= 10;
	}
	return cont;
}


long long int recursion(long long int n){
	long long int r,pot,aux;
	long long int NumDigit = numD(n);
	if (NumDigit == 1) {
		if (n == 0 || n == 1)r = 1;
		else r = n;
	}
	else {
		pot = pow(10, NumDigit-1);
		r = n / pot;
		aux = r * pow(10, NumDigit-1);
		r = r - 1;
		if (r != 0) {
			r = r * pow(9, NumDigit - 1);
			r = r + recursion(n - aux);
		}
		else {
			aux = n - aux + 1;
			r = n - aux;
			r = recursion(r);
		}
	}
	return r;
}


/////
bool recursion(int num) {
	bool b = false;
	if (num % 10 != 1)b = true;
	if (num > 0)
		b = b && recursion(num / 10);
	return b;
}
/////

int main() {
	long long int num;
	int numC;
	cin >> numC;

	int cont = 0;
	bool b;
	while (numC > 0) {
		cin >> num;
		cout << recursion(num) << endl;
		numC--;
	}


	///////////////
	while (numC > 0) {
		cin >> num;
		cont = 0;
		while (num >= 0) {
			b = false;
			b = recursion(num);
			if (b)cont++;
			num--;
		}
		cout << cont << endl;
		numC--;
	}
	//////////////
	
	return 0;
}
*/










/*
void resuelveCaso() {
	int num;
	int cant;
	cin >> num;
	cant=recursion(num)


	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}*/