#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	bool col[n];
	bool row[n];
	bool diag[2 * n - 1];
	bool diag2[2 * n - 1];
	for (int i = 0; i < n; i++) {
		col[i] = false;
		row[i] = false;
	}
	for (int i = 0; i < 2 * n - 1; i++) {
		diag[i] = false;
		diag2[i] = false;
	}
	bool ok = false;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		--x;
		--y;

		if (row[x] || col[y] || diag[x + y] || diag2[2 * n + y - x]) {
			cout << "yes";
			ok = true;	
		}
		row[x] = true;
		col[y] = true;
		diag[x + y] = true;
		diag2[2 * n + y - x] = true;
	}
	if (!ok) {
		cout << "no";
	}
	
	return 0;
}