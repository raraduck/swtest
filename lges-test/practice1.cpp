#include <iostream>
#include <vector>

using namespace std;

#define DEBUG 1

const int INF = 1e9;
int N, Q;
vector<vector<int>> Mat;
vector<vector<int>> Qs0;
vector<vector<int>> Qs1;
vector<int> solve(int N, int Q, vector<vector<int>>& Mat, vector<vector<int>>& Qs){
    vector<int> results;

    for (auto& q : Qs){
        int x = q[0], y = q[1], k = q[2];
        vector<vector<int>> dp(k+1, vector<int>(N, INF));
        dp[0][x] = 0;

        for (int step = 1; step <= k; step++) {
            for (int i = 0; i < N; i++) {
                if (dp[step-1][i] == INF) continue;
                for (int j=0; j < N; j++){
                    int t = Mat[i][j];
                    if (t == -1) continue;
                    int new_dist = dp[step-1][i] + t;
                    if (new_dist < dp[step][j]) {
                        dp[step][j] = new_dist;
                    }
                }
            }
        }
        int ans = INF;
        for (int step = 0; step <= k; step++) {
            ans = min(ans, dp[step][y]);
        }
        results.push_back(ans < INF ? ans:-1);
    }

    return results;
}
int main() {
    if (DEBUG){
        N=3, Q=5;
        Mat = {
            {0, 10, 5},
            {-1, 0, 3},
            {-1, 4, 0}
        };
        Qs1 = {
            {1, 2, 2},
            {1, 2, 1},
            {1, 3, 3},
            {2, 2, 1},
            {2, 1, 3}
        };
    }
    
    // 1-based to 0-based 변환

    for (auto& q : Qs1) {
        int x = q[0], y = q[1], k = q[2];
        Qs0.push_back({x-1, y-1, k});
    }

    // for (int i=0; i<Qs1.size(); i++){
    //     for (int j=0; j<3; j++) cout << Qs1[i][j] << " ";
    //     cout << "\n";
    // }
    
    // for (int i=0; i<Qs0.size(); i++){
    //     for (int j=0; j<3; j++) cout << Qs0[i][j] << " ";
    //     cout << "\n";
    // }

    vector<int> res = solve(N, Q, Mat, Qs0);
    for (auto r : res){
        cout << r << " ";
    }

    return 0;
}