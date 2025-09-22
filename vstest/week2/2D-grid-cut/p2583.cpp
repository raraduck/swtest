#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

#define DEBUG 0

struct Pos {
    int x1;
    int y1;
    int x2;
    int y2;
};

int dy[4] = {-1,  0,  1,  0};
int dx[4] = { 0,  1,  0, -1};

int dfs(int y, int x, vector<vector<int>>& mat, int c){
    c += 1;
    mat[y][x] = 2;
    for (int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if ((int)mat.size() > ny && ny >= 0 && (int)mat[0].size() > nx && nx >= 0){
            if (mat[ny][nx] == 1){
                c = dfs(ny, nx, mat, c);
            }
        }
    }
    return c;
}

int main(){
    // int M=5, N=7, K=3;
    int M, N, K;
    cin >> M >> N >> K;
    vector<vector<int>> Mat(M, vector<int>(N, 1));
    vector<Pos> rects;
    for (int i=0; i<K; i++){
        Pos tmp;
        cin >> tmp.x1 >> tmp.y1 >> tmp.x2 >> tmp.y2;
        rects.push_back(tmp);
    }
    // vector<Pos> rects={
    //     {0,2,4,4},
    //     {1,1,2,5},
    //     {4,0,6,2}
    // };

    if (DEBUG){
        for (auto row : Mat){
            for (auto el : row){
                cout << el << " ";
            }
            cout << "\n";
        }
    }
    for (int y=0; y<M; y++){
        for (int x=0; x<N; x++){
            for (auto p : rects){
                if (p.y2 > y && y >= p.y1 && p.x2 > x && x >= p.x1){
                    Mat[y][x] = 0;
                }
            }
        }
    }
    if (DEBUG){
        for (auto row : Mat){
            for (auto el : row){
                cout << el << " ";
            }
            cout << "\n";
        }
    }

    vector<int> ret;
    for (int y=0; y<M; y++){
        for (int x=0; x<N; x++){
            if (Mat[y][x] == 1){
                int cnt = 0;
                cnt = dfs(y, x, Mat, cnt);
                ret.push_back(cnt);
            }
        }
    }

    sort(ret.begin(), ret.end());
    cout << ret.size() << "\n";
    for (auto el : ret){
        cout << el << " ";
    }
    return 0;
}