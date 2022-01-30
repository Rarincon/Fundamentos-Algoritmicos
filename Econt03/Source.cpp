#include <iostream> 
#include <vector>
using namespace std;

bool problema(const vector<int> &a, const int & D, int ini, int fin ) {
	if (ini == fin) {
		return true;
	}
	else {
		int m = (ini + fin) / 2;
		if (abs(a.at(ini) - a.at(fin))>= D) {
			return (problema(a, D, ini, m) && problema(a, D, m + 1, fin));
		}
		else return false;
	}
}

bool resuelve() {
	int T, D, b;
	vector<int> a;
	cin >> T;
	if (!cin)return false;
	cin >> D;
	for (int i = 0; i < T; i++) {
		cin >> b;
		a.push_back(b);
	}
	if (problema(a,D,0,T-1))cout << "SI" << endl;
	else cout << "NO" << endl;

	return true;
}

int main() {
	while (resuelve());
	return 0;
}