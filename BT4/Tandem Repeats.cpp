#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

const int base = 311;
const long long MOD = 1e9 + 7;
const int maxN = 1e5 + 1;
long long hashS[maxN];
long long POW[maxN];

long long Pow(long long a, long long b) {
	if (b == 0) {
		return 1;
	}
	long long t = Pow(a, b / 2);
	t = t * t % MOD;
	if (b % 2) {
		t = t * a % MOD;
	}
	return t;
}

long long get(int i, int j) {
	return (hashS[j] - hashS[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	s = ' ' + s;
	POW[0] = 1;
	for (int i = 1; i <= n; i++) {
		POW[i] = (POW[i - 1] * base) % MOD;
	}
	hashS[0] = 0;
	for (int i = 1; i <= n; i++) {
		hashS[i] = (hashS[i - 1] * base + s[i]) % MOD;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		int len = y - x + 1;
		
		int left = 0;
		int right = (n - y) / len;
		
		while (left < right) {
			int mid = (left + right + 1) / 2;
			int last = y + len * mid;
			long long correctVal = get(x, last);
			long long bigBase = POW[len];
			long long unitVal = get(x, y);
			long long checkingVal = unitVal * (Pow(bigBase, mid + 1) - 1) % MOD * Pow(bigBase - 1, MOD - 2) % MOD;
			
			if (correctVal == checkingVal) {
				left = mid;
			}
			else {
				right = mid - 1;
			}
		}
		cout << left + 1 << '\n';
	}
	return 0;
}