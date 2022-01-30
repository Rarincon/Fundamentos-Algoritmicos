#include <iostream>
#include <vector>
using namespace std;

bool problema(const vector<int>& a, const int & N, int &num) {
	int suma = 0, i = N - 1;
	bool ok = false;
	while (!ok && i >= 0) {
		if (a.at(i) == suma) {
			num = i;
			ok = true;
		}
		else {
			suma += a.at(i);
			i--;		
		}
	}
	return ok;
}

void resuelve() {
	int N,b;
	vector<int>a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> b;
		a.push_back(b);
	}
	int num;
	if (problema(a, N, num))cout << "SI " << num << endl;
	else cout << "NO" << endl;
}

int main() {
	int i = 0, casos;
	cin >> casos;
	while (i < casos) {
		i++;
		resuelve();
	}
	return 0;
}