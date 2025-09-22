#include <iostream>
#include <string>
#include <vector>
#include <algorithm>   // ✅ 여기 추가!
#include <deque>

#define DEBUG 0
using namespace std;

struct Pos {
    int y;
    int x;
    int v;
};

int dy[] = {-1, 0, 1, 0};
int dx[] = { 0, 1, 0,-1};
void display(vector<vector<int>>& mat, int n, int m) {
    cout << "\n";
    for (int y=1; y<=n; y++){
        for (int x=1; x<=m; x++){
            cout << mat[y][x] << " ";
        }
        cout << endl;
    }
    cout << "\n";
}

int bfs(deque<Pos>& dq, vector<vector<int>>& mat, int n, int m){
    // Pos pos = dq.front();
    // dq.pop_front();
    // if (DEBUG) cout << pos.x << " " << pos.y << " " << pos.v;
    // int y = pos.y;
    // int x = pos.x;
    // int v = pos.v;
    while(dq.size()){
        Pos pos = dq.front();
        dq.pop_front();
        int y = pos.y;
        int x = pos.x;
        int v = pos.v;
        mat[y][x] = 2;
        if (DEBUG) display(mat, n, m);
        if (y == n && x == m) {
            return v;
        }
        for (int d=0; d<4; d++){
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (ny >= 1 && ny <= n && nx >= 1 && nx <= m ){
                if (mat[ny][nx] == 1){
                    mat[ny][nx] = 2;
                    dq.push_back({ny, nx, v+1});
                }
            }
        }
    }
    return -1;
}

int main() {
    int N, M;
    cin >> N >> M;
    // int Arr[1000][1000] = {};
    vector<vector<int>> Arr(100, vector<int>(100));
    for (int y=1; y<=N; y++){
        string tmp;
        // getline(cin, tmp);
        // tmp.erase(remove(tmp.begin(), tmp.end(), ' '), tmp.end());
        cin >> tmp;
        for (int x=1; x<=M; x++){
            Arr[y][x] = int(tmp[x-1] - '0');
        }
    }
    // if (DEBUG) display(Arr, N, M);
    deque<Pos> dq; 
    Pos pos = {1, 1, 1};
    dq.push_back(pos);
    
    int ret = bfs(dq, Arr, N, M);

    cout << ret;
    return 0;
}
