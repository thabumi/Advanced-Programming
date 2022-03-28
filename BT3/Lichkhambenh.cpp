#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;
using namespace std::chrono;

const int N = 300000;

/*
n = 45000: 4587, 4530, 4524
n = 47500: 5078, 5090, 5099
n = 50000: 5826, 5736, 5742
*/

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    vector<int> permutation(N);
    for (int i = 0; i < N; i++) {
    	permutation[i] = i;
	}
    shuffle(permutation.begin(), permutation.end(), rng);
	
	
	int n;
	cin >> n;
	auto start = high_resolution_clock::now();
	//Bubble sort
	///* 
	long long a[n];
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		a[i] = permutation[i];
//		cin >> a[i];
	}
	
//	for (int i = 0; i < n; i++) {
//		bool swapped = false;
//		for (int j = i + 1; j < n; j++) {
//			if (a[i] > a[j]) {
//				swap(a[i], a[j]);
//				swapped = true;
//			}
//		}
//		if (!swapped) {
//			break;
//		}
//	}	
	for (int i = 0; i < n; i++) {
		sum += a[i] * (n - 1 - i);
	}
	cout << sum << '\n';
	//*/
	
//	long long a[n];
//	long long sum = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	sort(a, a + n);
//	for (int i = 0; i < n; i++) {
//		sum += a[i] * (n - 1 - i);
//	}
//	cout << sum << '\n';
	
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
 
    cout << "Time taken by function: " << duration.count() << " milliseconds" << '\n';
	return 0;
}