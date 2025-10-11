#include <iostream>
#include <vector>
#define DEBUG 0
#define RELEASE 1

using namespace std;

vector<int> dy={-1, 0, 1, 0};
vector<int> dx={0, 1, 0, -1};

int N, M;
vector<vector<int>> Mat;
void display(vector<vector<int>>& mat) {
    cout << ">>>\n";
    for (int y=0; y<N; y++) {
        for (int x=0; x<M; x++) {
            cout << mat[y][x] << " ";
        }
        cout << "\n";
    }
    cout << "<<<\n";
}
void dfs(int y, int x, vector<vector<int>>& visited) {
    visited[y][x] = 1;
    if (DEBUG) display(Mat);
    for (int i=0; i<4; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if (N>ny && ny>=0 && M>nx && nx >=0) {
            if (Mat[ny][nx] == 1) {
                Mat[ny][nx] = 0;
                visited[ny][nx] = 1;
                if (DEBUG) display(visited);
            }
            if (Mat[ny][nx]==0 && visited[ny][nx] == 0){
                dfs(ny, nx, visited);
            }
        }
    }
}
int main() {
    if (RELEASE) ios::sync_with_stdio(false);
    if (RELEASE) cin.tie(NULL);

    cin >> N >> M;
    Mat = vector<vector<int>> (N, vector<int>(M));
    for (int y=0; y<N; y++) {
        for (int x=0; x<M; x++){
            cin >> Mat[y][x];
        }
    }
    vector<vector<int>> Visited(N, vector<int>(M, 0));  

    // if (DEBUG) display(Mat);
    // if (DEBUG) display(Visited);
    auto flag = [](vector<vector<int>>& arr){
        int n0s = 0;
        for (int y=0; y<N; y++){
            for (int x=0; x<M; x++){
                if (arr[y][x] != 0) n0s+=1;
            }
        }
        return n0s;
    };
    int cnt=0;
    int n0s=flag(Mat);
    pair <int, int> prev={cnt, n0s};
    while(n0s) {
        cnt+=1;
        Visited = vector<vector<int>> (N, vector<int>(M, 0));
        dfs(0, 0, Visited);
        n0s=flag(Mat);
        if (n0s==0) {
            cout << cnt << "\n";
            cout << prev.second << "\n";
        } else {
            prev={cnt, n0s};
        }
    }
    // cout << cnt << ": " << n0s << "\n";

    return 0;
}