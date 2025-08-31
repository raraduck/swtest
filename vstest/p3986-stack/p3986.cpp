#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define DEBUG 0
int main(){
    int N;
    cin >> N;
    vector<string> W;
    string w;
    for (int i=1; i<=N; i++) {
        cin >> w;
        W.push_back(w);
    }
    if (DEBUG) {
        for (auto w : W) {
            cout << w << '\n';
        }
    }
    vector<char> stack;
    int cnt = 0;
    for (auto w : W) {
        stack.clear();
        for (auto c : w) {
            if (stack.size() == 0) {
                stack.push_back(c);
            } else {
                if (c == stack.back()) {
                    stack.pop_back();
                } else {
                    stack.push_back(c);
                }
            }
        }
        if (stack.size() == 0) {
            cnt += 1;
        }
    }
    cout << cnt;
    return 0;
}

// int main() {
//     cout << "\n";
//     vector<int> V;
//     V.push_back(10);
//     V.push_back(20);
//     V.push_back(30);
//     for (auto v : V){
//         cout << v << " ";
//     }
//     cout << "\n";
//     int A = V.back();
//     V.pop_back();
//     int B = V.back();
//     V.pop_back();
//     cout << "\n";
//     cout << A << "\n";
//     cout << B << "\n";
//     cout << V.back() << "\n";
//     V.pop_back();
//     cout << V.size() << "\n";
//     return 0;
// }