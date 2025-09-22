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
		cout << "���ĺ� �ҹ��ڷθ� �̷���� �ܾ� S�� �־�����. �� ���ĺ��� �ܾ �� ���� ���ԵǾ� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�." << "\n";
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