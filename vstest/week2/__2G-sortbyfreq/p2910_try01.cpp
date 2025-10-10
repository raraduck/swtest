#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define DEBUG 0
#define RELEASE 1

struct meta {
    string key;
    int freq;
    int priority;
};
int N;
string C;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> C;

    vector<string> Ns(N);
    map<string, int> cntNs;
    vector<meta> sortItemsByFreq;

    for(int i=0; i<N; i++) {
        cin >> Ns[i];
        if (cntNs[Ns[i]] == 0) {
            sortItemsByFreq.push_back({Ns[i], 0, i});
        };
        cntNs[Ns[i]]+=1;
    }
    for (auto& p:sortItemsByFreq){
        p.freq = cntNs[p.key];
    }
    sort(
        sortItemsByFreq.begin(), 
        sortItemsByFreq.end(), 
        [](meta a, meta b){
            if (a.freq == b.freq) return a.priority < b.priority;
            return a.freq > b.freq;

        }
    );

    for (auto item : sortItemsByFreq){
        for (int i=0; i<item.freq; i++){
            cout << item.key << " ";
        }
    }

    return 0;
}