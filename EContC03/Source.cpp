#include <iostream>
#include <vector>
using namespace std;

int problema(const vector<int>& a, int ini, int fin) {
	if (ini == fin)return ini;
	else {
		int m = (ini + fin) / 2;
		if (a.at(m) == a.at(m - 1)) {
			int c = (m - 2) - ini + 1;
			if (c % 2 == 0)return problema(a, m + 1, fin);
			else return problema(a, ini, m - 2);
		}
		else if (a.at(m) == a.at(m + 1)) {
			int c =fin- (m +2) + 1;
			if (c % 2 == 0)return problema(a, ini, m - 1);
			else return problema(a, m+2, fin);
		}
		else return m;
	}
}

void resuelve() {
	int N, b;
	vector<int>a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> b;
		a.push_back(b);
	}
	cout << problema(a, 0, N - 1)<<endl;
}

int main() {
	int casos, i = 0;
	cin >> casos;
	while (i < casos) {
		i++;
		resuelve();
	}
	return 0;
}