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
struct meta2 {
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
    map<string, meta2> cntNs;
    vector<meta> sortItemsByFreq;

    for(int i=0; i<N; i++) {
        cin >> Ns[i];
        if (cntNs[Ns[i]].freq == 0) {
            sortItemsByFreq.push_back({Ns[i], 0, i});
            cntNs[Ns[i]].priority=i;
        };
        cntNs[Ns[i]].freq+=1;
        // cntNs[Ns[i]].priority = (i < cntNs[Ns[i]].priority) ? i:cntNs[Ns[i]].priority;
    }
    for (auto& p:sortItemsByFreq){
        p.freq = cntNs[p.key].freq;
    }
    sort(
        sortItemsByFreq.begin(), 
        sortItemsByFreq.end(), 
        [cntNs](meta a, meta b){
            // if (a.freq == b.freq) return a.priority < b.priority;
            if (a.freq == b.freq) return cntNs.at(a.key).priority < cntNs.at(b.key).priority;
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