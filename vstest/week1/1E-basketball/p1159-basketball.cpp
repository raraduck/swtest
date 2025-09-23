#include <iostream>
#include <vector>
#include <map>
using namespace std;

//6
//michael
//jordan
//lebron
//james
//kobe
//bryant

namespace P1159 {
	int main() {
		int N;
		string Name;
		map<char,vector<string>> MV;
		map<char, int> MC;

		cin >> N;
		for (int i = 0; i < N; i++) {
			vector<string> v;
			cin >> Name;
			MV[Name[0]].push_back(Name);
			MC[Name[0]] += 1;
		}
		bool done = false;
		for (auto mc : MC) {
			if (mc.second >= 5) {
				cout << mc.first;
				done = true;
			}
		}
		cout << '\n';
		cout << '\n';
		if (done) {
			for (auto mv : MV) {
				if (MC[mv.first] >= 5) {
					for (auto v : mv.second) cout << v << '\n';
				}
			}
		}
		if (!done) cout << "PREDAJA";

		return 0;
	}
}