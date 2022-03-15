#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>

using namespace std;

const int DRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int DCol[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool openSquare(char** board, bool** opened, bool** checked, int n, int m, int x, int y, int& cntSafe);
bool openSquares(char** board, bool** opened, bool** checked, int n, int m, int x, int y, int& cntSafe);

void init(char** board, bool** opened, bool** checked, int n, int m, int k, int& cntSafe) {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	pair<int, int> permutation[n * m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			permutation[i * m + j].first = i;
			permutation[i * m + j].second = j;
		}
	}
	shuffle(permutation, permutation + n * m, rng);
	for (int i = 0; i < k; i++) {
		board[permutation[i].first][permutation[i].second] = 'B';
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'B') {
				continue;
			}
			board[i][j] = '0';
			for (int k = 0; k < 8; k++) {
				int x = i + DRow[k];
				int y = j + DCol[k];
				if (x < 0 || x >= n || y < 0 || y >= m) {
					continue;
				}
				if (board[x][y] == 'B') {
					board[i][j]++;
				}
			}
		}
	}
	
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			opened[i][j] = false;
			checked[i][j] = false;
		}	
	}
	cntSafe = n * m - k;
}

void print(char** board, bool** opened, bool** checked, int n, int m) {
	
	for (int i = -1; i < n; i++) {
		for (int j = -1; j < m; j++) {
			if (i == -1 || j == -1) {
				if (i == -1 && j == -1) {
					cout << setw(3) << " ";
				}
				else if (i == -1) {
					cout << setw(3) << j;
				}
				else {
					cout << setw(3) << i;
				}
			}
			else if (opened[i][j]) {
				cout << setw(3) << board[i][j];
			}
			else if (checked[i][j]) {
				cout << setw(3) << "F";
			}
			else {
				cout << setw(3) << "-";
			}
		}
		cout << '\n';
	}
}

bool openSquare(char** board, bool** opened, bool** checked, int n, int m, int x, int y, int& cntSafe, bool spread) {
	if (!opened[x][y] && !checked[x][y]) {
		opened[x][y] = true;
		if (board[x][y] != 'B') {
			cntSafe--;
		}
		if (board[x][y] == '0') {
			openSquares(board, opened, checked, n, m, x, y, cntSafe);
		}
		else {
			for (int i = 0; i < 8; i++) {
				int x0 = x + DRow[i];
				int y0 = y + DCol[i];
				if (x0 < 0 || x0 >= n || y0 < 0 || y0 >= m) {
					continue;
				}
				if (board[x0][y0] == '0' && spread) {
					openSquares(board, opened, checked, n, m, x0, y0, cntSafe);
				}
			}
		}
		return board[x][y] != 'B';
	}
	return true;
}

bool openSquares(char** board, bool** opened, bool** checked, int n, int m, int x, int y, int& cntSafe) {
	bool safe = true;
	for (int i = 0; i < 8; i++) {
		int x0 = x + DRow[i];
		int y0 = y + DCol[i];
		if (x0 < 0 || x0 >= n || y0 < 0 || y0 >= m) {
			continue;
		}
		safe &= openSquare(board, opened, checked, n, m, x0, y0, cntSafe, false);
	}
	return safe;
}
bool spreadable(char** board, bool** opened, bool** checked, int n, int m, int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		int x0 = x + DRow[i];
		int y0 = y + DCol[i];
		if (x0 < 0 || x0 >= n || y0 < 0 || y0 >= m) {
			continue;
		}
		if (checked[x0][y0] || (board[x0][y0] == 'B' && opened[x0][y0])) {
			cnt++;
		}
	}
	return (cnt >= board[x][y] - '0');
}

void Guide() {
	cout << "Pls choose the size of the board and the number of mines\n";
	cout << "Some options:\n";
	cout << "Beginner: 9 * 9 board, 10 mines\n";
	cout << "Intermediate: 16 * 16 board, 40 mines\n";
	cout << "Advanced: 24 * 24 board, 99 mines\n";
	cout << "Example:\n9 9 10\n16 16 40\n";
	cout << "Three types of move:\n";
	cout << "First type: x y 1, open the (x, y) cell\n";
	cout << "Second type: x y 2, flag the (x, y) cell\n";
	cout << "Third type: x y 3, open all 8 adjacent cells of the opened (x, y) cell, except the flagged ones\n";
}

int main() {
	Guide();
	int n, m, k;
	while (cin >> n >> m >> k) {
		if (n <= 0 || m < 0 || k > n * m) {
			cout << "Invalid board!\n";
			continue;
		}
		break;
	}
	int cntSafe;
	char** board = new char*[n];
	bool** opened = new bool*[n];
	bool** checked = new bool*[n];
	for (int i = 0; i < n; i++) {
		board[i] = new char[m];
		opened[i] = new bool[m];
		checked[i] = new bool[m];
	}
	init(board, opened, checked, n, m, k, cntSafe);
	print(board, opened, checked, n, m);
	int x, y, type;
	while (cin >> x >> y >> type) {
		if (x < 0 || x >= n || y < 0 || y >= m || (type != 1 && type != 2 && type != 3)) {
			cout << "Invalid move!\n";
			continue;
		}
		if (type == 1) {
			if (opened[x][y] || checked[x][y]) {
				cout << "Invalid move!\n";
				continue;
			}
			bool stillGood = openSquare(board, opened, checked, n, m, x, y, cntSafe, true);
			print(board, opened, checked, n, m);
			if (!stillGood) {
				cout << "YOU'RE DEAD!";
				break;
			}
		}
		else if (type == 2) {
			if (opened[x][y]) {
				cout << "Invalid move!\n";
				continue;
			}
			checked[x][y] = 1 ^ checked[x][y];
			print(board, opened, checked, n, m);
		}
		else if (type == 3) {
			if (!opened[x][y]) {
				cout << "Invalid move!\n";
				continue;
			}
			if (spreadable(board, opened, checked, n, m, x, y)) {
				bool stillGood = openSquares(board, opened, checked, n, m, x, y, cntSafe);
				print(board, opened, checked, n, m);
				if (!stillGood) {
					cout << "YOU'RE DEAD!";
					break;
				}
			}
		}
		if (cntSafe <= 0) {
			cout << "YOU WON!";
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		delete []board[i];
		delete []opened[i];
		delete []checked[i];
	}
	delete []board;
	delete []opened;
	delete []checked;
	return 0;
}