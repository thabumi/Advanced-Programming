#include <iostream>

using namespace std;

struct myString {
	private:
		int sz;
		char* str;
	public:
		myString(const char* init) {
			int n = strlen(init);
			sz = n;
			str = new char[sz];
			for (int i = 0; i < n; i++) {
				str[i] = init[i];
			}
		}
		void deleteString() {
			sz = 0;
			delete []str;
		}
		void print() {
			for (int i = 0; i < sz; i++) {
				cout << str[i];
			}
			cout << '\n';
		}
		void append(const char* other) {
			int n = strlen(other);
			char* tmp = new char[sz + n];
			for (int i = 0; i < sz; i++) {
				tmp[i] = str[i];
			}
			for (int i = sz; i < sz + n; i++) {
				tmp[i] = other[i - sz];
			}
			swap(tmp, str);
			sz = sz + n;
			delete[] tmp;
		}
};

int main() {
	myString a = myString("Hello");
	a.print();
	a.append(" World!");
	a.print();
	a.deleteString();
	return 0;
}