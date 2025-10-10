#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

#define DEBUG 0

int main() {
    // int N = 8;
    // int C = 3;
    // vector<int> Nums {1, 3, 3, 2, 2, 2, 1, 1};

    int N;
    int C;
    vector<int> Nums;
    cin >> N >> C;
    for (int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        Nums.push_back(tmp);
    }
    vector<pair<int, int>> key_val;
    vector<int> ret;
    map <int, int> mNums;
    map <int, int> iNums;

    int i = 0;
    for (auto el : Nums) {
        mNums[el] += 1;
        if (iNums[el] == 0) {
            iNums[el] = i+1;
        }
        i++;
    }

    for (auto el : mNums){
        key_val.push_back({el.first, el.second});
    }

    if (DEBUG){
        for (auto el : Nums) {
            cout << el << " ";
        }
        cout << endl;
        for (auto el : mNums){
            cout << el.first << ": " << el.second << "\n";
        }
        cout << endl;
        for (auto el : key_val){
            cout << el.first << ", " << el.second << "\n";
        }
    }

    sort(key_val.begin(), key_val.end(),
        [iNums](const pair<int, int> a, const pair<int, int> b){
            if (a.second == b.second){
                // return iNums[a.first] < iNums[b.first];
                return iNums.at(a.first) < iNums.at(b.first);  // 안전
            }
            return a.second > b.second;
        });

    if (DEBUG){
        cout << endl;
        for (auto el : key_val){
            cout << el.first << ", " << el.second << "\n";
        }
    }

    // for (auto el : key_val) {
    //     for (int i=0; i<el.second; i++){
    //         ret.push_back(el.first);
    //     }
    // }
    
    for (auto el : key_val){
        for (int i=0; i<el.second; i++){
            // ret.push_back(el.first);
            cout << el.first << " ";
        }
    }
    return 0;
}