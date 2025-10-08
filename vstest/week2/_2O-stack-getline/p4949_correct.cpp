#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, char> checker={
    {'(',')'},
    {')','('},
    {'[',']'},
    {']','['}
};

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    string S;
    int cont=1;
    while(cont) {
        getline(cin, S);
        // char c1=S[0];
        // if (S.size()==1 && c1=='.') {cont=0;break;}
        
		if (S == ".") break;

        vector<char> ST;
        for (int i=0; i<S.size(); i++) {
            char c=S[i];
            // if (c=='.') {
            //     if (i < S.size()-1) {
            //         ST.push_back(c);
            //         break;
            //     }
            // }
            // c1=c;
            if (c == '(' || c == '[') {
                ST.push_back(c);
            } else if (c == ')' || c == ']') {
                if (ST.size() == 0) {
                    ST.push_back(c);
                    break;
                } else {
                    char c0 = ST.back();
                    if (c == checker[c0]) {
                        ST.pop_back();
                    } else {
                        ST.push_back(c);
                        break;
                    }
                }
            }
        }
        if (ST.size()==0) {
            cout << "yes" << "\n";
        } else {
            cout << "no" << "\n";
            ST.clear();
        }
    }
    return 0;
}