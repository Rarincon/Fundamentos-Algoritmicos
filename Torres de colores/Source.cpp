#include <iostream>
using namespace std;

//1 es rojo
//0 es azul
//2 es verde

const int MAX = 100;

typedef struct{
	int cant = 0;
	int max;
}Color;

typedef Color color[3];

bool verdes(int sol[MAX], int k) {
	if (sol[k] == 2 && sol[k - 1] == 2)return true;
	else return false;
}

bool azul(color & col) {

	if (col[0].cant == 0 && col[2].cant == 0)return true;
	else if (col[0].cant >= col[2].cant) return true;
	else return false;
}

void vuelta2(const int& N, color & col, bool& ok, int sol[MAX], int k) {
	for (int i = 0; i < 3; i++) {
		sol[k] = i;
		col[i].cant++;
		if (!verdes(sol, k) && azul(col) && col[i].cant <= col[i].max){
			if (k == N - 1) {
				if (col[1].cant > (col[0].cant + col[2].cant)) {
					ok = true;
					for (int i = 0; i < N; i++) {
						if (sol[i] == 1)cout << "rojo ";
						else if (sol[i] == 0)cout << "azul ";
						else cout << "verde ";
					}
					cout << endl;
				}
			}
			else vuelta2(N, col, ok, sol, k + 1);
		}
		col[i].cant--;
	}
}


bool vuelta(const int &N, const int& a, const int& r, const int&v) {
	bool ok = false;
	color col;
	col[0].max = a;
	col[1].max = r;
	col[2].max = v;
	col[1].cant += 1;
	int sol[MAX];
	sol[0] = 1;
	vuelta2(N, col, ok, sol, 1);
	return ok;
}

bool resuelveCaso() {
	int alt, a, r, v;
	cin >> alt >> a >> r >> v;
	if (alt ==0 && a ==0 && r ==0 && v == 0)
		return false;
	else {
		bool ok = vuelta(alt, a, r, v);
		if (!ok)cout << "SIN SOLUCION" << endl;
		return true;
	}
}

int main() {
	while (resuelveCaso());
	return 0;
}