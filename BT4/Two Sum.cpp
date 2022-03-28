#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int target;
	cin >> target;
	sort(a, a + n);
	int i = 0;
	int j = n - 1;
	bool ok = false;
	while (i < j) {
		if (a[i] + a[j] == target) {
			cout << a[i] << " " << a[j];
			ok = true;
			break;
		}
		else if (a[i] + a[j] < target) {
			i++;
		}
		else {
			j--;
		}
	}
	if (!ok) {
		cout << "No";
	}
	
	return 0;
}