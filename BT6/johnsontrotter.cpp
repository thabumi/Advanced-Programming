#include <bits/stdc++.h>

using namespace std;

void process(int n, int sz, int** a) {
	if (n == 1) {
		a[0][0] = 1;
		return;
	}
	process(n - 1, sz / n, a);
	for (int i = sz - 1; i >= 0; i--) {
		int ord = i / n;
		if (ord % 2 == 0) {
			int orderOfN = n - 1 - i % n;
			a[i][orderOfN] = n;
			int j = 0;
			int k = 0;
			while (j < n) {
				if (j != orderOfN) {
					a[i][j] = a[ord][k++];
				}
				j++;
			}
		}
		else {
			int orderOfN = i % n;
			a[i][orderOfN] = n;
			int j = 0;
			int k = 0;
			while (j < n) {
				if (j != orderOfN) {
					a[i][j] = a[ord][k++];
				}
				j++;
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int sz = 1;
    for (int i = 1; i <= n; i++) {
    	sz *= i;
	}
	int** a = new int*[sz];
	for (int i = 0; i < sz; i++) {
		a[i] = new int[n];
	}
	process(n, sz, a);
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << '\n';
	}
	for (int i = 0; i < sz; i++) {
		delete []a[i];
	}
	delete []a;
    return 0;
}
