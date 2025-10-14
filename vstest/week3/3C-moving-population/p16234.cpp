#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define DEBUG 1
#define RELEASE 0

vector<int> dy={-1, 0, 1, 0};
vector<int> dx={0, 1, 0 -1};
int N, L, R;
vector<vector<int>> Nations;
bool check(int n0, int n1) {
    int diff = abs(n0-n1);
    return ( R >= diff ) && ( diff >= L);
}
int dfs(int y, int x, vector<vector<int>>& visited){
    for (int i=0; i<4; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if (N>ny && ny>=0 && N>nx && nx>=0){
            bool valid = check(Nations[y][x], Nations[ny][nx]);
            if (visited[ny][nx]==0 && valid){
                visited[ny][nx]=1;
                dfs(ny, nx, visited);
            }
        }
    }
    return 0;
}
int main() {
    if (RELEASE) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
    }

    cin >> N >> L >> R;
    Nations=vector<vector<int>>(N, vector<int>(N));
    vector<vector<int>> Visited(N, vector<int>(N,0));
    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            cin >> Nations[y][x];
        }
    }

    int cnt=0;
    while(true){
        for(auto& row:Visited) fill(row.begin(), row.end(), 0);
        
        for(int y=0; y<N; y++){
            for (int x=0; x<N; x++){
                if (Visited[y][x] == 0){
                    Visited[y][x]=1;
                    dfs(y,x,Visited);
                }
            }
        }
    }
    return 0;
}