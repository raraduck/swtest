#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG 0
#define RELEASE 1

using namespace std;

int N, M;
vector<vector<int>> mAdj;
// vector<vector<int>> Adj;
void dfs(int n, int* cnt, vector<int>& visited) {
    visited[n]=1;
    for (auto t : mAdj[n]) {
        if (visited[t]==0){
            *cnt += 1;
            dfs(t, cnt, visited);
        }
    }
}
int main() {
    if (RELEASE) {ios::sync_with_stdio(false);cin.tie(NULL);};
    cin >> N >> M;
    mAdj=vector<vector<int>>(N+1);
    // Adj=vector<
    for (int i=0; i<M; i++){
        int y;
        int x;
        cin >> x >> y;
        mAdj[y].push_back(x);
        // mAdj[y][x]=1;
    }

    // if (DEBUG) {
    //     for (int y=1; y<=N; y++) {
    //         for (int x=1; x<=N; x++) {
    //             cout << mAdj[y][x] << " ";
    //         }
    //         cout << "\n";
    //     }
    // }

    
    vector<pair<int,int>> Cases;
    vector<int> Ret;
    int maxCnt = 0;
    for (int i=1; i<=N; i++) {
        int cnt=0;
        vector<int> Visited(N+1);
        dfs(i, &cnt, Visited);
        if (cnt > maxCnt) maxCnt = cnt;
        Cases.push_back({i, cnt});
        // cout << "root: " << i << ", cnt:" << cnt << "\n";
    }
    for (auto c : Cases){
        if (c.second == maxCnt) cout << c.first << " ";
        // if (c.second == maxCnt) Ret.push_back(c.first);
        // cout << "root: " << c.first << ", cnt: " << c.second << "\n";
    }
    // sort(Ret.begin(), Ret.end());
    // for (auto i : Ret) cout << i << " ";

    return 0;
}