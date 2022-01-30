#include <iostream>
#include <vector>
using namespace std;

bool resuelve(const vector<int>& a, const int& N, const int& rep) {
	int i = 0;
	for (int i = 0; i < N-1; i++) {
		if (a.at(i) != a.at(i + 1))
			if((a.at(i)+1) != a.at(i + 1))return false;
		if (i + rep < N && a.at(i) == a.at(i + rep))return false;
		
	}
	return true;
}
	
int main() {
	int rep, N,b,casos,i=0;
	vector<int> a;
	int c[10];
	for (int j = 0; j < 10; j++)
		c[j] = j;
	

	cin >> casos;
	while (i < casos) {
		cin >> rep >> N;
		for (int j = 0; j < N; j++) {
			cin >> b;
			a.push_back(b);
		}
		bool ok= resuelve(a, N, rep);
		if (ok)cout << "SI" << endl;
		else cout << "NO" << endl;
		a.clear();
		i++;
	}
	return 0;
}