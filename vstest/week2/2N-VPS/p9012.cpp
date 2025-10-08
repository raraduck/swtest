#include <iostream>
#include <string>
#include <vector>

using namespace std;

int T;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;

    string PS;
    while (T--){
        cin >> PS;
        vector<char> Stack;
        for (auto c : PS){
            if (Stack.size()==0) {
                Stack.push_back(c);
                if (c==')') {
                    break;
                }
            } else {
                char c0 = Stack.back();
                if (c0 != c) {
                    Stack.pop_back();
                } else {
                    Stack.push_back(c);
                }
            }
        }
        if (Stack.size()==0) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }

    return 0;
}