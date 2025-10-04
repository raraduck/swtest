#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <algorithm>

using namespace std;

string stripLeadingZeros(const string &s) {
    // "000123" -> "123", "0000" -> "0"
    size_t pos = s.find_first_not_of('0');
    if (pos == string::npos) return "0"; // 모두 0
    return s.substr(pos);
}

bool bigIntLess(const string &a, const string &b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b; // 길이가 같으면 사전식 비교
}

int main(){
    int N;
    
    vector<string> W_list={
        // "lo3za4",
        // "01"

        // "43silos0",
        // "zita002",
        // "le2sim",
        // "231233"
    };
    cin >> N;
    for (int i = 0; i < N; i++){
        string tmp;
        cin >> tmp;
        W_list.push_back(tmp);
    }
    vector<string> Num_list;
    regex re("[a-z]+");  // 알파벳 기준 split

    for (auto &w : W_list) {
        sregex_token_iterator it(w.begin(), w.end(), re, -1);
        sregex_token_iterator end;
        for (; it != end; ++it) {
            string token = *it;
            if (!token.empty()) {
                Num_list.push_back(stripLeadingZeros(token));
            }
        }
    }

    sort(Num_list.begin(), Num_list.end(), bigIntLess);

    // 결과 출력
    for (auto &num : Num_list) {
        cout << num << endl;
    }

    return 0;
}