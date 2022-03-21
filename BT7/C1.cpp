#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>

using namespace std;

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int pntA = 0;
	int pntB = 0;
	bool turnA = true;
	while (pntA != 100 && pntB != 100) {
		int x = (rng() % 6 + 6) % 6 + 1;
		if (turnA) {
			cout << "A: " << x << '\n';
			if (pntA + x <= 100) {
				pntA += x;
			}
		}
		else {
			cout << "B: " << x << '\n';
			if (pntB + x <= 100) {
				pntB += x;
			} 
		}
//		turnA ^= 1;
		turnA = (pntA <= pntB);
		cout << pntA << " " << pntB << '\n';
	}
	if (pntA == 100) {
		cout << "A";
	}
	else {
		cout << "B";
	}
//	for (int i = 1; i <= 100; i++) {
//		int a = rng();
//		cout << (a % 6 + 6) % 6 + 1 << " ";
//	}
	return 0;
}