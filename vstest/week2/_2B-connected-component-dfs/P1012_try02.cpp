#include <iostream>
#include <vector>

using namespace std;

#define DEBUG 1

vector<int> dy = {-1, 0, 1, 0};
vector<int> dx = {0, 1, 0, -1};

void dfs(int y, int x, vector<vector<int>>& mat, int n, int m) {
    mat[y][x] = 2;

    for (int i=0; i < 4; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if (n > ny && ny >=0  && m > nx && nx >= 0) {
            if (mat[ny][nx] ==1 ) {
                dfs(ny, nx, mat, n, m);
            }
        }
    }
}

int main(){
    int T;
    int M, N, K;

    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> M >> N >> K;
        vector<vector<int>> Mat(N, vector<int> (M));
        for (int i = 0; i < K; i++) {
            int X, Y;
            cin >> X >> Y;
            Mat[Y][X]=1;
        }

        int cnt = 0;

        for (int y=0; y<N; y++) {
            for (int x=0; x<M; x++) {
                if (Mat[y][x] == 1) {
                    dfs(y, x, Mat, N, M);
                    cnt += 1;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}