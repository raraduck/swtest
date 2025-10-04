#include <iostream>
#include <string>
#include <vector>
#include <algorithm>   // ✅ 여기 추가!
#include <deque>

#define DEBUG 0
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = { 0, 1, 0,-1};

void display(int mat[][100], int n, int m) {
    cout << "\n";
    for (int y=0; y<n; y++){
        for (int x=0; x<m; x++){
            cout << mat[y][x] << " ";
        }
        cout << endl;
    }
    cout << "\n";
}

void dfs(int y, int x, int mat[][100], int N, int M){
    mat[y][x] = 2;
    if (DEBUG) display(mat, N, M);
    for (int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        int is_land = 0;
        if (N > ny && ny >=0 && M > nx && nx >= 0){
            is_land = mat[ny][nx];
        }
        if (is_land == 1){
            dfs(ny, nx, mat, N, M);
        }
    }
}

int main(){
    ios::sync_with_stdio(false); // C I/O와 C++ I/O를 분리해서 더 빠르게
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, M, K;
    int Arr[100][100] = {};
    cin >> T;
    
    for (int t=1; t <= T; t++){
        cin >> M >> N >> K;
        fill(&Arr[0][0], &Arr[0][0] + 100*100, 0);
        
        for (int k=1; k<=K; k++){
            int y, x;
            cin >> x >> y;
            Arr[y][x] = 1;
        }
        if (DEBUG) display(Arr, N, M);

        int cnt = 0;
        for (int y=0; y<N; y++){
            for (int x=0; x<M; x++){
                if (Arr[y][x] == 1) {
                    dfs(y, x, Arr, N, M);
                    cnt += 1;
                }
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}