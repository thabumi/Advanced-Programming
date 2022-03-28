<<<<<<< HEAD
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>

using namespace std;

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int rabbit = 0;
	int turtle = 0;
	int rabStep[] = {3, 3, 3, 3, 3, 1, 1, 1, -6, -6};
	int turStep[] = {0, 0, 9, 9, -12, 1, 1, 1, -2, -2};
	
	int finish = 70;
	while (rabbit < finish && turtle < finish) {
		int k = (rng() % 10 + 10) % 10;
		rabbit += (rabStep[k]);
		if (rabbit < 0) {
			rabbit = 0;
		}	
		if (rabbit > finish) {
			rabbit = finish;
		}
		k = (rng() % 10 + 10) % 10;
		turtle += (turStep[k]);
		if (turtle < 0) {
			turtle = 0;
		}	
		if (turtle > finish) {
			turtle = finish;
		}
		cout << "R: " << turtle << '\n';
		cout << "T: " << rabbit << '\n';
	}
	return 0;
=======
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>

using namespace std;

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int rabbit = 0;
	int turtle = 0;
	int rabStep[] = {3, 3, 3, 3, 3, 1, 1, 1, -6, -6};
	int turStep[] = {0, 0, 9, 9, -12, 1, 1, 1, -2, -2};
	
	int finish = 70;
	while (rabbit < finish && turtle < finish) {
		int k = (rng() % 10 + 10) % 10;
		rabbit += (rabStep[k]);
		if (rabbit < 0) {
			rabbit = 0;
		}	
		if (rabbit > finish) {
			rabbit = finish;
		}
		k = (rng() % 10 + 10) % 10;
		turtle += (turStep[k]);
		if (turtle < 0) {
			turtle = 0;
		}	
		if (turtle > finish) {
			turtle = finish;
		}
		cout << "R: " << turtle << '\n';
		cout << "T: " << rabbit << '\n';
	}
	return 0;
>>>>>>> 642dd62715126b6c36dca7e56ed9c0ff5410e257
}