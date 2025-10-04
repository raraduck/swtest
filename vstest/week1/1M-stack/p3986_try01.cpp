#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    int cnt;
    int ret=0;
    cin >> cnt;
    while(cnt--) {
        cin >> s;
        vector<char> stack;
        for (auto c : s){
            if (stack.size() == 0) {
                stack.push_back(c);
            } else {
                if (stack.back() == c) stack.pop_back();
                else stack.push_back(c);
            }
        }
        if (stack.size() == 0) {
            // cout << "GOOD\n";
            ret += 1;
        } else {
            // cout << "BAD\n";
        }
    }
    cout << ret;
    return 0;
}