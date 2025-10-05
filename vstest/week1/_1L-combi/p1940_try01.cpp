#include <iostream>
#include <vector>

using namespace std;

int ret = 0;
int M;

void display(vector<int>& arr) {
    int sum = 0;
    for (int i=0; i<arr.size(); i++) {
        sum += arr[i];
        // cout << arr[i] << " ";
    }
    // cout << " = " << sum << " ? " << (sum==M);
    // cout << "\n";
    if (sum == M ) ret += 1;
}

void combi(int n, int r, int offset, vector<int>& bag, vector<int>& els){
    if (bag.size()==2) {
        display(bag);
    } else {
        for (int i=offset; i<n; i++) {
            bag.push_back(els[i]);
            combi(n, r, i+1, bag, els);
            bag.pop_back();
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    vector<int> Els;

    cin >> N;
    cin >> M;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        Els.push_back(tmp);
    }

    // N=6;
    // M=9;
    // Els = {2, 7, 4, 1, 5, 3};

    // for (int i = 0; i < Els.size(); i++) {
    //     cout << Els[i] << " ";
    // }
    // cout << "\n";
    vector<int> Bag;
    combi(N, 2, 0, Bag, Els);
    cout << ret;
    return 0;
}