#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
#define DEBUG 1
struct obj{
    int val;
    int freq;
    int priority;
};
int N;
int C;
vector<int> Arr;
map<int, int> Counter;
map<int, int> Priority;
vector<obj> Obj;
void runCounter(){
    for(int i=0; i<N; i++){
        int el = Arr[i];
        Priority[el] = N;
    }
    for(int i=0; i<N; i++){
        int el = Arr[i];
        Priority[el]=min(i, Priority[el]);
        Counter[el] += 1;
    }
}
int main() {
    if (DEBUG) {
        // N=5, C=2;
        // Arr={2, 1, 2, 1, 2};

        // N=9, C=3;
        // Arr={1, 3, 3, 3, 2, 2, 2, 1, 1};

        N=9, C=77;
        Arr={11 ,33 ,11, 77, 54 ,11 ,25 ,25, 33};
    }
    runCounter();
    // for (auto el:Counter){
    //     cout << el.first << ": " << el.second << "\n";
    // }
    for (int i=0; i<N; i++){
        int el = Arr[i];
        // Priority[el]=min(i, Priority[el]);
        Obj.push_back({el, Counter[el], Priority[el]});
    }

    sort(Obj.begin(), Obj.end(), [](obj a, obj b){
        if (a.freq == b.freq) return a.priority < b.priority;
        else {
            return a.freq > b.freq;
        }
    });
    
    for (auto el : Obj){
        cout << el.val << " ";
    }
    return 0;
}