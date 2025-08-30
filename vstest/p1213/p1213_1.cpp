#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <cctype>   // toupper, tolower
using namespace std;
int main(){
    string STR;
    cin >> STR;
    map<char, int> M;
    for (auto c : STR){
        // if (c < 'A' || c > 'Z') {
        //     cout << "I'm Sorry Hansoo";
        //     return 0;
        // }
        char C = toupper(c);
        M[C]+=1;
    }
    int flag = 0;
    for (auto m:M){
        if (m.second %2 == 1) flag += 1;
    }
    if (flag >=2 ) {
        // cout << "I'm Sorry Hansoo";
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    string S1;
    string S2;
    char mid;
    for (int i='Z'; i>='A'; i--){
        if (M[i]){
            while(M[i] > 0) {
                if (M[i] == 1){
                    mid = char(i);
                    M[i] -= 1;
                } else if (M[i] > 1) {
                    S1 = char(i) + S1;
                    S2 = S2 + char(i);
                    M[i] -= 2;
                }
            }
        }
    }
    string S;
    if (mid) S = S1 + mid + S2;
    else S = S1 + S2;
    cout << S;
    return 0;
}