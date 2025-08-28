#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace  std;
//1 2 3  4  5  6  7  8 9 10
//1 1 1  1  1  1
//    2  2  2
//  3 3  3  3  3  3  3
//a b c  c  c  b  a  a
//5 8 9 10 11 14 19 24

namespace P2979 {
	int A, B, C;
	int sum = 0;
	pair <int, int> T1, T2, T3;
	int CNT[100] = {};
	void main() {
		cin >> A >> B >> C;
		cin >> T1.first >> T1.second;
		cin >> T2.first >> T2.second;
		cin >> T3.first >> T3.second;

		for (int i = 0; i < 100; i++) {
			if (i >= T1.first and i < T1.second) CNT[i]++;
			if (i >= T2.first and i < T2.second) CNT[i]++;
			if (i >= T3.first and i < T3.second) CNT[i]++;
		}
		//int i = 0;
		//for (int c : cnt) {
		//	cout << c << ' ';
		//	if (++i % 10 == 0) cout << '\n';
		//}
		//for (int cnt : CNT) {
		//	if (cnt == 1) sum += 1*A;
		//	if (cnt == 2) sum += 2*B;
		//	if (cnt == 3) sum += 3*C;
		//	cout << cnt << '(' << sum << ')' << ' ';
		//}
		cout << sum << '\n';
		return;
	}
}