#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define DEBUG 1
bool is_pallindrom(string s){
    // string r = s;
    // reverse(s.begin(), s.end());
    // return s==r;
    for (int i =0; i<s.size(); i++){
        if (s[i] != s[s.size()-1-i]){
            return false;
        }
    }
    return true;
}
int main(){
    string STR;
    cin >> STR;
    sort(STR.begin(), STR.end());
    if (DEBUG){
        cout << STR;
        cout << "\n";
    };
    do{
        if (is_pallindrom(STR)) {
            cout << STR << "\n";
            return 0;
        }
    }while(next_permutation(STR.begin(), STR.end()));
    cout << "I'm Sorry Hansoo";
    return 0;
}