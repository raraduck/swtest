#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

	int main() {
		string S;
		string T;
		//cout << "P11655";
		getline(cin, S);   // 줄 전체 입력 받기
		for (int i = 0; i < S.size(); i++) {
			if (S[i] >= 'A' and S[i] <= 'Z') {
				int TMP = S[i] + 13;
				if (TMP > 'Z') {
					TMP -= ('Z' - 'A' + 1);
				}
				T += TMP;
			}
			else if (S[i] >= 'a' and S[i] <= 'z') {
				int TMP = S[i] + 13;
				if (TMP > 'z') {
					TMP -= ('z' - 'a' + 1);
				}
				T += TMP;
			}
			else {
				T += S[i];
			}
		}
		cout << T;
		return 0;
	}