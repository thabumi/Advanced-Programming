#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

int main() {
	int w, h;
	cin >> h >> w;
	char c[w][h];
	bool dp[w][h];
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			cin >> c[i][j];
			if (c[i][j] == 'Y') {
				dp[i][j] = 1;
			}
			else {
				dp[i][j] = 0;
			}
		}
	}
	for (int i = 1; i < w; i++) {
		for (int j = 0; j < h; j++) {
			if (c[i][j] == 'R' || c[i - 1][j] == 'R') {
				continue;
			}
			if (j > 0) {
				dp[i][j] |= dp[i - 1][j - 1];
			}
			dp[i][j] |= dp[i - 1][j];
			if (j < h - 1) {
				dp[i][j] |= dp[i - 1][j + 1];
			}
		}
	}
//	for (int i = 0; i < w; i++) {
//		for (int j = 0; j < h; j++) {
//			cout << dp[i][j];
//		}
//		cout << '\n';
//	}
	bool OK = false;
	for (int i = 0; i < h; i++) {
		OK |= dp[w - 1][i];
	}
	if (OK) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}