<<<<<<< HEAD
#include <iostream>

using namespace std;

void process(int n, int k, int a[], int sz) {
	if (n == 0) {
		for (int i = 0; i < sz; i++) {
			cout << a[i] << " ";
		}
		cout << '\n';
		return;
	}
	if (n < 0) {
		return;
	}
	for (int i = 1; i <= k; i++) {
		a[sz] = i;
		process(n - i, i, a, sz + 1);
	}
}

int main() {
    int n;
    cin >> n;
    int a[n];
    int sz = 0;
    process(n, n, a, sz);
    return 0;
}
=======
#include <bits/stdc++.h>

using namespace std;

void process(int n, int k, int a[], int sz) {
	if (n == 0) {
		for (int i = 0; i < sz; i++) {
			cout << a[i] << " ";
		}
		cout << '\n';
		return;
	}
	if (n < 0) {
		return;
	}
	for (int i = 1; i <= k; i++) {
		a[sz] = i;
		process(n - i, i, a, sz + 1);
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    int sz = 0;
    process(n, n, a, sz);
    return 0;
}
>>>>>>> 642dd62715126b6c36dca7e56ed9c0ff5410e257
