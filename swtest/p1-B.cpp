#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

string S;
map<char, int> M;
namespace P10808 {
	void main() {
		cout << int('a') << char(int('a')) << '\n';
		cout << int('z') << '\n';

		for (int c = int('a'); c <= int('z'); c++) {
			M[c] = 0;
		}
		cout << "알파벳 소문자로만 이루어진 단어 S가 주어진다. 각 알파벳이 단어에 몇 개가 포함되어 있는지 구하는 프로그램을 작성하시오." << "\n";
		cin >> S;
		cout << '\n';
		cout << S << '\n';

		for (char c : S) {
			M[c] += 1;
		}
		for (auto m : M) {
			cout << m.first << ' ';
		}
		cout << "\n";
		for (auto m : M) {
			cout << m.second << ' ';
		}
		return;
	}
}