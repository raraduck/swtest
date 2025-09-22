#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

#define DEBUG 0
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int Arr[100][100] = {};
int Mat[100][100] = {};

void display(int n, int arr[][100]){
    cout << ">>>\n";
    for (int y=0; y<n; y++){
        for (int x=0; x<n; x++){
            cout << arr[y][x] << " ";
        }
        cout << "\n";
    }
    cout << "<<<\n";
}

void dfs(int _y, int _x, int mat[][100], int N){
    mat[_y][_x] = 2;
    // Mat[ny][nx] = 2;
    
    for (int i=0; i < 4; i++){
        int ny = _y + dy[i];
        int nx = _x + dx[i];
        if (N > ny && ny >= 0 && N > nx && nx >= 0){
            if (mat[ny][nx] == 1) {
                dfs(ny, nx, mat, N);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); // C I/O와 C++ I/O를 분리해서 더 빠르게
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    // cout << N;
    int maxVal = 0;
    for (int r=0; r<N; r++){
        for (int c=0; c<N; c++){
            int tmp;
            cin >> tmp;
            Arr[r][c] = tmp;
            Mat[r][c] = tmp;
            if (tmp > maxVal){
                maxVal = tmp;
            }
        }
    }

    if (DEBUG) display(N, Arr);
    // cout << maxVal << "\n";
    int ret = 0;
    for (int level = 0; level <= maxVal; level++){
        int cnt = 0;
        for (int y=0; y<N; y++){
            for (int x=0; x<N; x++){
                if (Arr[y][x] <= level){
                    Mat[y][x] = 0;
                } else {
                    Mat[y][x] = 1;
                }
            }
        }
        if (DEBUG) cout << level << "\n";
        if (DEBUG) display(N, Mat);
        
        for (int y=0; y<N; y++){
            for (int x=0; x<N; x++){
                for (int i=0; i < 4; i++){
                    // cout << dy[i] << " " << dx[i] << "\n";
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (N > ny && ny >= 0 && N > nx && nx >= 0){
                        if (Mat[ny][nx] == 1) {
                            dfs(ny, nx, Mat, N);
                            cnt += 1;
                        }
                    }
                }
            }
        }
        if (cnt > ret) {
            ret = cnt;
        }
    }

    cout << ret;
    return 0;
}

