#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define DEBUG 1
#define RELEASE 0
int main(){
    if (RELEASE) ios::sync_with_stdio(false);
    if (RELEASE) cin.tie(NULL);

    int N;
    cin >> N;
    cin.ignore();
    auto get_numbers = [](string _S, vector<string>& Nums){
        string num="";
        for (auto c : _S) {
            if (c < '0' || c > '9') {
                if (num == "") {
                    continue;
                } else {
                    Nums.push_back(num); 
                    num="";
                }
            } else {
                num += c;
            }
        }
        if (num != "") Nums.push_back(num);
        return;
    };
    vector<string> Nums;
    while(N--){
        string S;
        getline(cin, S);
        get_numbers(S, Nums);
    }
    // auto erase_zeros = [](string _S){
    //     while(true){
    //         if (_S.size() && _S.front() == '0') _S.erase(_S.begin());
    //         else break;
    //     }
    //     if (_S.size() == 0) _S = "0";
    //     v.push_back(ret);
    //     ret = "";
    //     return _S;
    // };
    // for (auto& s:Nums) s=erase_zeros(s);
    
    auto nonzero_idx = [](string __S){
        for (int i=0; i<__S.size(); i++) if (__S[i] != '0') return i;
        return int(__S.size());
    };

    for (auto& s:Nums){
        int idx=nonzero_idx(s);
        if (idx == s.size()) s = "0";
        else s.erase(s.begin(), s.begin()+idx);
    }
    sort(Nums.begin(), Nums.end(), [](string a, string b){
        if (a.size() == b.size()) return a < b;
        return a.size() < b.size();
    });
    for (auto s:Nums) cout << s << "\n";
    return 0;
}