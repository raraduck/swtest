#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define DEBUG 0
int N;

void display(vector<vector<int>>& arr){
    for (int y=0; y<arr.size(); y++){
        for (int x=0; x<arr[0].size(); x++){
            cout << arr[y][x] << " ";
        }
        cout << "\n";
    }
    return;
}

vector<int> dy={-1, 0, 1, 0};
vector<int> dx={0, 1, 0, -1};

void dfs(int y, int x, vector<vector<int>>& arr) {
    arr[y][x] = 2;
    for (int i=0; i<4; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if (N>ny && ny>=0 && N>nx && nx>=0){
            if (arr[ny][nx] == 1){
                dfs(ny,nx,arr);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int max_level = 0;
    vector<vector<int>> Arr(N, vector<int>(N));
    for (int y=0; y<N; y++) {
        for (int x=0; x<N; x++){
            cin >> Arr[y][x];
            if (Arr[y][x] > max_level) max_level = Arr[y][x];
        }
    }
    if (DEBUG) cout << "\n";
    if (DEBUG) display(Arr);

    int ret=0;
    for (int level=0; level<=max_level; level++){
        vector<vector<int>> Arr2(N, vector<int>(N));
        for (int y=0; y<N; y++) {
            for (int x=0; x<N; x++) {
                if (Arr[y][x] <= level) Arr2[y][x] = 0;
                else Arr2[y][x] = 1;
            }
        }

        int cnt=0;
        for (int y=0; y<N; y++) {
            for (int x=0; x<N; x++){
                if (Arr2[y][x] == 1) {
                    dfs(y, x, Arr2);
                    cnt+=1;
                }
            }
        }
        // cout << "\n";
        if (DEBUG) cout << "level: " << level << ", " << cnt << "\n";
        if (DEBUG) display(Arr2);
        if (cnt > ret) ret = cnt;
    }
    if (DEBUG) cout << "\n";
    cout << ret;
    return 0;
}