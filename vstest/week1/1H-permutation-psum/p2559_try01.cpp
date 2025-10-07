#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    N=10; K=2;
    vector<int> V(N);
    V={3, -2, -4, -9, 0, 3, 7, 13, 8, -3};
    
    return 0;
}


// 3 -2 -4 -9 0 3 7 13 8 -3

// I 1 2 3 4 5 6 7 8 9
// V 1 1 1 1 1 1 1 1 1

// 0 1 1                 [0:2] psum[0]
// 1 1 1 1               [0:3] psum[1]
// 2 1 1 1 1             [0:4] psum[2]
// 3 1 1 1 1 1           [0:5] psum[3]
// 4 1 1 1 1 1 1         [0:6] psum[4]
// 5 1 1 1 1 1 1 1       [0:7] psum[5]
// 6 1 1 1 1 1 1 1 1     [0:8] psum[6]
// 7 1 1 1 1 1 1 1 1 1   [0:9] psum[7]

// 0 2 2                 [0:2] - [:0]  psum[0]
// 1   2 2               [0:3] - [:1]  psum[1]-V[0]
// 2     2 2             [0:4] - [0:2] psum[2]-psum[0]
// 3       2 2           [0:5] - [0:3] psum[3]-psum[1]
// 4           .         [0:6] - [0:4] psum[4]-psum[2]
// 5           .         [0:7] - [0:5] psum[5]-psum[3]
// 6           .         [0:8] - [0:6] psum[6]-psum[4]
// 7               2 2   [0:9] - [0:7] psum[7]-psum[5] 

//                                     psum[n]-psum[n-k]

