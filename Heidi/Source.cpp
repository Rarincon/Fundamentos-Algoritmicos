#include <iostream>
#include <vector>
using namespace std;

vector<int> resuelve(const vector<int>& a, const int& min, int& sec) {
	vector<int> c;
	int aux=1,max=0;
	int i = a.size() - 1;
	while (i >= 0) {
		if (a.at(i) > 1 && a.at(i) >= max) {
			int j = i - 1;
			while (j >= 0 && a.at(i) == a.at(j)) {
				aux++;
				j--;
			}
			if (aux >= min) {
				c.push_back(i);
				if (sec < aux)sec = aux;
			}
			max = a.at(i);
			aux = 1;
			i = j;
		}
		else i--;
	}
	return c;
}

int main() {
	int N,min,b,sec;
	vector<int> a,c;
	cin >> N;
	if (!cin)return 0;
	while (true) {
		cin >> min;
		sec = 0;
		for (int i = 0; i < N; i++) {
			cin >> b;
			a.push_back(b);
		}
		c = resuelve(a, min, sec);
		cout << sec << " "<< c.size()<<" ";
		for (int i = 0; i < c.size(); i++)cout << c.at(i) << " ";
		cout << endl;
		a.clear();
		cin >> N;
		if (!cin)return 0;
	}
	return 0;
}