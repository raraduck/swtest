#include <iostream>
#include <iomanip> 
#include <algorithm>

using namespace std;
#define DEBUG 1

int N;
vector<int> P;
vector<int> Stack;
int ret = 0;
void combi(int n, int r, int start) {
    if (Stack.size()==r){
        int sum = 0;
        for (int i=0; i<r; i+=2) sum+=Stack[i];
        for (int i=1; i<r; i+=2) sum-=Stack[i];
        cout << setw(3) << sum << "=";
        ret = max(ret, sum);
        for (auto el : Stack){
            cout << el << " ";
        }
        cout << "\n";
    }
    for (int i=start; i<n; i++){
        Stack.push_back(P[i]);
        combi(n, r, i+1);
        Stack.pop_back();
    }
}
int main() {
    if (DEBUG) {
        N=8;
        P={7, 2, 1, 8, 4, 3, 5, 6};
    } else {
        cin >> N;
        P = vector<int>(N);
        for (int i=0; i<N; i++) cin >> P[i];
    }
    for (int i=1; i<N; i+=2){
        combi(N, i, 0);
    }
    cout << "\n";
    cout << ret << "\n";
    return 0;
}