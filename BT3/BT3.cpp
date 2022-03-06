#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	long long a[n];
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		sum += a[i] * (n - 1 - i);
	}
	cout << sum;
	return 0;
}