#include <iostream>
using namespace std;

char f(char c) {
	return '.' + 'o' - c;
}

void process(int n, char** a, int rdmostRow, int rdmostCol) {
	if (n == 1) {
		return;
	}
//	cout << n << " " << rdmostRow << " " << rdmostCol << '\n';
	for (int i = rdmostRow - n / 2 + 1; i <= rdmostRow; i++) {
		for (int j = rdmostCol - n / 2 + 1; j <= rdmostCol; j++) {
			a[i][j] = f(a[i][j]);
		}
	}
	
	process(n / 2, a, rdmostRow, rdmostCol);
	process(n / 2, a, rdmostRow, rdmostCol - n / 2);
	process(n / 2, a, rdmostRow - n / 2, rdmostCol);
	process(n / 2, a, rdmostRow - n / 2, rdmostCol - n / 2);
}

int main() {
	int n;
	cin >> n;
	int sz = 1;
	for (int i = 0; i < n; i++) {
		sz *= 2;
	}
	char** a = new char*[sz];
	for (int i = 0; i < sz; i++) {
		a[i] = new char[sz];
		for (int j = 0; j < sz; j++) {
			a[i][j] = '.';
		}
	}
//	for (int i = 0; i < sz; i++) {
//		for (int j = 0; j < sz; j++) {
//			cout << a[i][j];
//		}
//		cout << '\n';
//	}
//	return 0;
	
	process(sz, a, sz - 1, sz - 1);
//	return 0;
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			cout << a[i][j];
		}
		cout << '\n';
	}
	return 0;
	for (int i = 0; i < sz; i++) {
		delete []a[i];
	}
	delete []a;
	return 0;
}