#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define DEBUG 0
struct rect {
    int sx;
    int sy;
    int ex;
    int ey;
};
void display(vector<vector<int>>& arr) {
    cout << ">>>\n";
    for (int y=0; y<arr.size(); y++){
        for (int x=0; x<arr[0].size(); x++) {
            cout << arr[y][x] << " ";
        }
        cout << "\n";
    }
}
int M, N, K;
vector<int> dy = {-1, 0, 1, 0};
vector<int> dx = {0, 1, 0, -1};
vector<int> islands;
void dfs(int y, int x, vector<vector<int>>& grid, int* area) {
    grid[y][x] = 2;
    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (M > ny && ny >= 0 && N > nx && nx >= 0) {
            if (grid[ny][nx] == 1) {
                dfs(ny, nx, grid, area);
                *area+=1;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N >> K;
    // M=5;
    // N=7;
    // K=3;

    vector<rect> R(K);
    for (auto& el : R) {
        cin >> el.sx >> el.sy >> el.ex >> el.ey;
    }
    // ={
    //     {0,2, 4,4},
    //     {1,1, 2,5},
    //     {4,0, 6,2}
    // };

    vector<vector<int>> grid(M,vector<int> (N, 1));

    if (DEBUG) display(grid);

    for (int y=0; y<M; y++){
        for (int x=0; x<N; x++) {
            for (auto r : R) {
                if (r.ey > y && y >= r.sy && r.ex > x && x >= r.sx) grid[y][x]=0;
            }
        }
    }

    if (DEBUG) display(grid);

    int cnt = 0;
    for(int y=0; y<M; y++) {
        for (int x=0; x<N; x++){
            if (grid[y][x] == 1) {
                int area=1;
                dfs(y, x, grid, &area);
                cnt += 1;
                islands.push_back(area);
            }
        }
    }

    if (DEBUG) display(grid);

    sort(islands.begin(), islands.end());
    cout << cnt << "\n";
    for (auto el : islands) {
        cout << el << " ";
    }
    cout << "\n";
    return 0;
}