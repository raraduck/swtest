#include <iostream>
#include <string>
using namespace std;

namespace P10988 {
	int main() {
		string S;
		cin >> S;
		for (int i = 0; i < S.size(); i++) {
			if (S[i] != S[S.size() - 1 - i]) {
				cout << 0;
				return 1;
			}
		}
		cout << 1;
		return 0;
	}
}