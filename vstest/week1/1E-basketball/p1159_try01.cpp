#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    // N=6;
    vector<string> Names;
    for (int i=0; i<N; i++) {
        string tmp;
        cin >> tmp;
        Names.push_back(tmp);
    }
    //  = {
    //     "michael",
    //     "jordan",
    //     "lebron",
    //     "james",
    //     "kobe",
    //     "bryant"

    //     // "babic",
    //     // "keksic",
    //     // "boric",
    //     // "bukic",
    //     // "sarmic",
    //     // "balic",
    //     // "kruzic",
    //     // "hrenovkic",
    //     // "beslic",
    //     // "boksic",
    //     // "krafnic",
    //     // "pecivic",
    //     // "klavirkovic",
    //     // "kukumaric",
    //     // "sunkic",
    //     // "kolacic",
    //     // "kovacic",
    //     // "prijestolonasljednikovi"
    // };

    map<char, int> cnt;

    for (auto name : Names) {
        cnt[name[0]] += 1;
    }

    vector<char> ret;
    for (auto item : cnt) {
        // cout << item.first << ": " << item.second << "\n";
        if (item.second >= 5) {
            ret.push_back(item.first);
        }
    }

    if (ret.size() == 0) {
        cout << "PREDAJA";
    } else {
        sort(ret.begin(), ret.end());
        // cout << '\n';
        // cout << '\n';
        for (auto c : ret) {
            cout << c;
        }
        // cout << "\n";
    }

    return 0;
}