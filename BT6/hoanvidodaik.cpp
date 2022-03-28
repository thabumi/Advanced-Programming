<<<<<<< HEAD
#include <iostream>

using namespace std;

void search(char subset[], int k, char permutation[], int sz, bool chosen[]) {
	if (sz == k) {
		for (int i = 0; i < k; i++) {
			cout << permutation[i];
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < k; i++) {
		if (chosen[i]) {
			continue;
		}
		chosen[i] = true;
		permutation[sz] = subset[i];
		search(subset, k, permutation, sz + 1, chosen);
		chosen[i] = false;
	}
}

void solve(int n, int k, char subset[], char permutation[], bool chosen[]) {
	for (int i = 0; i < (1 << n); i++) {
		int index = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				if (index >= k) {
					++index;
					break;
				}
				subset[index] = 'a' + j;
				++index;
				
			}
		}
		if (index == k) {
			search(subset, k, permutation, 0, chosen);
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;

	char subset[k];
	char permutation[k];
	bool chosen[k];
	memset(chosen, 0, sizeof(chosen));
	solve(n, k, subset, permutation, chosen);
	return 0;
=======
#include <iostream>

using namespace std;

void search(char subset[], int k, char permutation[], int sz, bool chosen[]) {
	if (sz == k) {
		for (int i = 0; i < k; i++) {
			cout << permutation[i];
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < k; i++) {
		if (chosen[i]) {
			continue;
		}
		chosen[i] = true;
		permutation[sz] = subset[i];
		search(subset, k, permutation, sz + 1, chosen);
		chosen[i] = false;
	}
}

void solve(int n, int k, char subset[], char permutation[], bool chosen[]) {
	for (int i = 0; i < (1 << n); i++) {
		int index = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				if (index >= k) {
					++index;
					break;
				}
				subset[index] = 'a' + j;
				++index;
				
			}
		}
		if (index == k) {
			search(subset, k, permutation, 0, chosen);
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;

	char subset[k];
	char permutation[k];
	bool chosen[k];
	memset(chosen, 0, sizeof(chosen));
	solve(n, k, subset, permutation, chosen);
	return 0;
>>>>>>> 642dd62715126b6c36dca7e56ed9c0ff5410e257
}