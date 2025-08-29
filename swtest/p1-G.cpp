#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

namespace P9996 {
	int main() {
		int N;
		string P, TMP;
		vector<string> V;
		cin >> N;
		cin >> P;

		size_t start = 0;
		size_t end;
		string head, tail;
		end = P.find('*', start);
		head = P.substr(start, end - start);
		end += 1;
		tail = P.substr(end, P.size() - end);
		//cout << head << " * " << tail << '\n';

		//cout << '\n';
		for (int i = 0; i < N; i++) {
			cin >> TMP;
			V.push_back(TMP);
		}
		//cout << '\n';


		for (int i = 0; i < N; i++) {
			if (head.size() + tail.size() > V[i].size()) {
				cout << "NE" << endl;
				continue;
			}
			string vhead = V[i].substr(0, head.size());
			string vtail = V[i].substr(V[i].size() - tail.size(), tail.size());
			if (vhead == head and vtail == tail) cout << "DA";
			else cout << "NE";
			if (i < N - 1) cout << "\n";
		}

		return 0;
	}
}