#include <iostream>

using namespace std;

void print(int row[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j != row[i]) {
				cout << '.';
			}
			else {
				cout << '*';
			}
		}
		cout << '\n';
	}
	cout << '\n';
}
void bt(int n, int row[], int col[], int diag1[], int diag2[], int y) {
	if (y == n) {
		print(row, n);
		return;
	}
	for (int x = 0; x < n; x++) {
		if (col[x] || diag1[x + y] || diag2[x - y + n - 1]) {
			continue;
		}
		col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
		row[y] = x;
		bt(n, row, col, diag1, diag2, y + 1);
		col[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
	}
}

int main() {
	int n;
	cin >> n;
	
	int row[n], col[n], diag1[2 * n - 1], diag2[2 * n - 1];
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	memset(diag1, 0, sizeof(diag1));
	memset(diag2, 0, sizeof(diag2));
	
	bt(n, row, col, diag1, diag2, 0);
	
	return 0;
}