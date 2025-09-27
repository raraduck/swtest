#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
#define DEBUG 1

void print(string _S){
    for (auto s : _S){
        cout << s << " ";
    }
    cout << endl;
    return;
}

int main() {
    string S;
    cin >> S;
    if (DEBUG) print(S);
    char prev_1;
    char prev_2;
    for (auto s : S){
        if(DEBUG) cout << s << "-" << prev_1 << "-" << prev_2 << endl;
        prev_2 = prev_1;
        prev_1 = s;
    }

    return 0;
}