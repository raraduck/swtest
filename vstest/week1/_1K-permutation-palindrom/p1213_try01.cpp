#include <iostream>
#include <vector>
// #include <stack>
#include <map>
#include <string>

using namespace std;

int main(){
    string s;
    while(cin >> s){
        map <char, int> wcnt;
        for (auto c : s) {
            wcnt[c]+=1;
        }
        int cnt = 0;
        string ret1 = "";
        string ret2 = "";
        string mid = "";
        for (auto &el : wcnt) {
            // cout << el.first << ": " << el.second << "\n";
            if (el.second%2 == 1) {
                cnt += 1;
                if (cnt >= 2) {
                    cout << "I'm Sorry Hansoo";
                    return 0;
                }
            };
            while(el.second) {
                if (el.second == 1) {
                    el.second -= 1;
                    mid = el.first;
                } else {
                    el.second -= 2;
                    ret1 += el.first;
                    ret2 = el.first + ret2;   // 'A'를 맨 앞에 붙임
                }
            }
        };
        cout << ret1 + mid + ret2 << endl;
    }
    return 0;
}