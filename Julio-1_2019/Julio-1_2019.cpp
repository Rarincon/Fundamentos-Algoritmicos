#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000;

int record(int N, const vector <int>& a) {
	int i, f, x, cont_aux;
	i = 0;
	f = i + 1;
	cont_aux = 0;
	x = 0;
	while (f < N) {
		if (a[i] >= a[f]) {
			cont_aux++;
			if (cont_aux > x)
				x = cont_aux;
		}
		else {
			cont_aux = 0;
			i = f;
		}
		f++;
	}
	return x;
}

int main() {
	int cant, N, num;
	cin >> cant;
	for (int i = 0; i < cant; i++) {
		cin >> N;
		vector<int> a;
		for (int j = 0; j < N; j++) {
			cin >> num;
			a.push_back(num);
		}
		cout << record(N, a) << endl;
	}
	return 0;
}


// {N>0}
// fun(entero a[N])devuelve x: int
// {x=( max ini,fin: 0<=ini<fin<N: a[ini}-a[fin])}

//Invariante
//I= 0<=i<f<=N & a[i]>=a[f] & x=(max i,j:ini<=i<f<=fin : a[i}-a[f])
//T=N-f-1
//O(N) recorre todo el array, para buscar la mayor diferencia




/*int main() {
	int cant, N, a[MAX];
	cin >> cant;
	for (int i = 0; i < cant; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> a[j];
		}
		cout << record(N, a) << endl;
	}
	return 0;
}*/


///////////////////////////////////////////////////////

/*
int record(int N) {
	int i, marca1,marca2, cont, cont_aux;
	i = 0;
	cont_aux = 0;
	cont = 0;
	cin >> marca1;
	while (i < N-1) {
		cin >> marca2;
		if (marca1 >= marca2) {
			cont_aux++;
			if (cont_aux > cont)cont = cont_aux;
		}
		else {
			cont_aux = 0;
			marca1 = marca2;
		}
		i++;
	}
	return cont;
}


int main() {
	int cant, N;
	cin >> cant;
	for (int i = 0; i < cant; i++) {
		cin >> N;
		cout << record(N) << endl;
	}
	return 0;
}*/

// {N>0}
// fun(entero N)devuelve x: int
// x= max i,j: 0<=i<j<=N: i-j 
// En nuestro ejercicio x=cont, i= marca1, j=marca2

//I= marca1>=marca2
//T=N-i-1
//O(N) lee tantas veces, como elementos hay para calcular la diferencia