// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;
#define DEBUG 0

int N, M, Answer;
vector<int> S;

void combi(int n, int r, int start, vector<int> &L) {
    if (L.size() == r) {
        int sum = 0;
        for (int i=0; i<r; i++){
            if (DEBUG) cout << L[i] << " ";
            sum += L[i];
        }
        if (sum == M){
            if (DEBUG) cout << ": " << sum << " * \n";
            Answer += 1;
        } else {
            if (DEBUG) cout << ": " << sum << "\n";
        }
    } else {
        for (int i=start; i < n; i++) {
            L.push_back(S[i]);
            combi(n, r, i+1, L);
            L.pop_back();
        }
    }
}
int main(){
    int tmp;
    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        cin >> tmp;
        S.push_back(tmp);
    }
    cout << "\n";
    if (DEBUG) {
        for (int i=0; i<N; i++){
            cout << S[i] << " ";
        }
        cout << "\n";
    }
    vector<int> L;
    combi(N, 2, 0, L);
    cout << Answer;
    return 0;
}
