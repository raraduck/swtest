#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int N, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // N=10; K=2;
    cin >> N >> K;
    map<int, int> val;
    map<int, int> psum;
    map<int, int> seq;
    // vector<int> tmp={3, -2, -4, -9, 0, 3, 7, 13, 8, -3};

    for (int i=1;i<=N;i++){
        // val[i]=tmp[i-1];
        cin >> val[i];
    }

    int sum=0;
    for (int i=1; i<=N; i++){
        sum+=val[i];
        psum[i]=sum;
    }
    sum=0;
    for (int i=1; i<=N; i++){
        if (K > i){
            seq[i]=psum[K]-psum[i];
        } else {
            seq[i]=psum[i]-psum[i-K];
        }
    }
    // cout << "\n";
    int max=seq[K];
    for (int i=K; i<=N; i++){
        if (seq[i] > max) max = seq[i];
        // cout << seq[i] << " ";
    }
    // cout << "\n";
    cout << max << "\n";
    // cout << max(1,2,3);
    return 0;
}


// 3 -2 -4 -9 0 3 7 13 8 -3

// I 1 2 3 4 5 6 7 8 9
// V 1 1 1 1 1 1 1 1 1

// K = 3
// psum[-3]
// psum[-2]
// psum[-1]
// 0 1 1 1               [0:3] psum[0]
// 1 1 1 1 1             [0:4] psum[1]
// 2 1 1 1 1 1           [0:5] psum[2]
// 3 1 1 1 1 1 1         [0:6] psum[3]
// 4 1 1 1 1 1 1 1       [0:7] psum[4]
// 5 1 1 1 1 1 1 1 1     [0:8] psum[5]
// 6 1 1 1 1 1 1 1 1 1   [0:9] psum[6]

// 0 2 2 2               [0:3] - [:0]  psum[0]          
// 1   2 2 2             [0:4] - [:1]  psum[1]-V[0]     
// 2     2 2 2           [0:5] - [0:2] psum[2]-V[0]-V[1]
// 3       2 2 2         [0:6] - [0:3] psum[3]-psum[0]
// 4         2 2 2       [0:7] - [0:4] psum[4]-psum[1]
// 5           2 2 2     [0:8] - [0:5] psum[5]-psum[2]
// 6             2 2 2   [0:9] - [0:7] psum[6]-psum[3] 

//                                     psum[n]-psum[n-k]

