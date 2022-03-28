<<<<<<< HEAD
#include <iostream>

using namespace std;

void solve(int n, int k, char subset[], bool chosen[]) {
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
			for (int i = 0; i < k; i++) {
				cout << subset[i];
			}
			cout << '\n';
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;

	char subset[k];
	bool chosen[k];
	memset(chosen, 0, sizeof(chosen));
	solve(n, k, subset, chosen);
	return 0;
=======
#include <iostream>

using namespace std;

void solve(int n, int k, char subset[], bool chosen[]) {
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
			for (int i = 0; i < k; i++) {
				cout << subset[i];
			}
			cout << '\n';
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;

	char subset[k];
	bool chosen[k];
	memset(chosen, 0, sizeof(chosen));
	solve(n, k, subset, chosen);
	return 0;
>>>>>>> 642dd62715126b6c36dca7e56ed9c0ff5410e257
}