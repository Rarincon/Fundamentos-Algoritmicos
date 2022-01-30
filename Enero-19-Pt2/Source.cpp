#include <iostream>
#include <vector>

using namespace std;

int prob(const vector<int>& a, const vector<int>& b, int ini, int fin) {
	if (ini == fin + 1)return ini - 1;
	else {
		int m = (ini + fin) / 2;
		if (a[m] < b[m])return prob(a, b, m + 1, fin);
		else if (a[m] == b[m])return m;
		else return prob(a, b, ini, m - 1);
	}
}

bool resuelve() {
	int N, pos;
	cin >> N;
	vector<int>a(N);
	vector<int>b(N);
	if (!cin)return false;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	for (int i = 0; i < N; i++)
		cin >> b[i];

	pos = prob(a, b, 0, N - 1);
	cout << pos << " " << pos + 1 << endl;
	return true;
}

int main() {
	while (resuelve());
	return 0;
}