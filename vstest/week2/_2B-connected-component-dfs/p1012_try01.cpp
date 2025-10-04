#include <iostream>
#include <vector>

using namespace std;
#define DEBUG 0

void display(int N, int M, int y, int x, vector<vector<int>>& mat) {

    cout << "\n";
    cout << M << ", " << N << ", (" << y << ", " << x << ")";
    cout << "\n";
    for (auto row : mat) {
        for (auto v : row) {
            cout << v << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    return;
}
vector<int> dy = {-1, 0, 1, 0};
vector<int> dx = {0, 1, 0, -1};
void dfs(int N, int M, int y, int x, vector<vector<int>>& mat){
    mat[y][x] = 2;
    if (DEBUG) display(N, M, y, x, mat);
    for (int i=0; i<4; i++){
        int ny = y + dy[i], nx = x + dx[i]; // North
        if (N > ny && ny >= 0 && M > nx && nx >= 0) {
            if (mat[ny][nx] == 1) {
                dfs(N, M, ny, nx, mat);
            }
        }
    }

}

int main() {
    int T;
    int M, N, K;
    
    // T=1;
    // M=10;
    // N=10;
    // K= 2;

    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> M >> N >> K;

        vector<vector<int>> Mat(N, vector<int>(M));

        for (int i =0; i < K; i++) {
            int X, Y;
            cin >> X >> Y;
            Mat[Y][X]=1;
        }

        if (DEBUG) display(N, M, 0, 0, Mat);

        int cnt = 0;
        for (int y=0; y<N; y++) {
            for (int x=0; x<M; x++){
                if (Mat[y][x] == 1) {
                    dfs(N, M, y, x, Mat);
                    cnt += 1;
                }
            }
        }
        // cout << '\n';
        cout << cnt;
        cout << '\n';
    }
    
    return 0;
}