#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define DEBUG 0

void print(string _S){
    for (auto s : _S){
        cout << s << " ";
    }
    cout << endl;
    return;
}

map<char, int> vckr {
    make_pair('a', 1),
    make_pair('i', 1),
    make_pair('o', 1),
    make_pair('u', 1),
    make_pair('e', 1)
};

int checker1(string _s) {
    return vckr[_s[0]];
}

int checker3(string s, string prev1, string prev2){
    bool is_e_or_o = [](string _s){
        return (_s == "e" || _s == "o");
    }(s);
    if (is_e_or_o) {
        if (s == prev1 && s == prev2) return 1;
        else return 0;
    } else {
        if (s == prev1) return 1;
        else return 0;
    }
}

int main() {
    string S;
    while(true) {
        cin >> S;
        if (S == "end") {   // 문자열 비교 가능
            break;
        }
        if (DEBUG) print(S);
        string prev_1;
        string prev_2;
        int vcnt = 0;
        int cnt3 = 0;
        int lcnt = 0;
        int i =0;
        for (auto c : S){
            vcnt += checker1(string(1, c));
            if (i >= 2){
                cnt3 += [](string s, string prev1, string prev2) {
                    int is_v0 = vckr[s[0]];
                    int is_v1 = vckr[prev1[0]];
                    int is_v2 = vckr[prev2[0]];
                    if (is_v0 == is_v1 && is_v0 == is_v2) return 1;
                    else return 0;
                }(string(1, c), prev_1, prev_2);
            }
            lcnt += (i >= 1) ? checker3(string(1, c), prev_1, prev_2) : 0;

            if(DEBUG) cout << (vcnt > 0) << ": "<< (cnt3==0) << ": " << (lcnt==0) << ": " << c << "-" << prev_1 << "-" << prev_2 << ": " << endl;
            prev_2 = prev_1;
            prev_1 = c;
            i++;
        }
        if ((vcnt > 0) && (cnt3==0) && (lcnt==0)){
            cout << "<" << S << ">" << " is acceptable." << endl;
        } else {
            cout << "<" << S << ">" << " is not acceptable." << endl;
        }
    }

    return 0;
}