#include <iostream>
#include <vector>

using namespace std;

#define DEBUG 0
#define RELEASE 1

struct pos {
    int y;
    int x;
};
int N, M;
int max_cnt=0;
void display(vector<vector<int>>& arr){
    cout << ">>>\n";
    for (int y=0; y<N; y++){
        for (int x=0; x<M; x++){
            cout << arr[y][x] << " ";
        }
        cout << "\n";
    }
    cout << "<<<\n";
}
vector<int> dy = {-1, 0, 1, 0};
vector<int> dx = {0, 1, 0, -1};
void dfs(int y, int x, vector<vector<int>>& arr){
    arr[y][x]=3;
    for (int i=0; i<4; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if (N>ny && ny>=0 && M>nx && nx>=0){
            if (arr[ny][nx]==0) dfs(ny, nx, arr);
        }
    }
}
void combi(int n, int r, int offset, vector<pos>& combiPos, vector<pos>& emptyPos, vector<vector<int>>& ori_Mat){
    if (combiPos.size()==r){
        vector<vector<int>> new_Mat=ori_Mat;
        for (int i=0; i<r; i++) {
            if (DEBUG) cout << "(" << combiPos[i].y << ", " << combiPos[i].x << "), ";
            // if (DEBUG) cout << combiPos[i] << " ";
            int y=combiPos[i].y;
            int x=combiPos[i].x;
            new_Mat[y][x]=1;
        }
        if (DEBUG) cout << "\n";
        if (DEBUG) display(new_Mat);
        for (int y=0; y<N; y++) {
            for (int x=0; x<M; x++) {
                if (new_Mat[y][x]==2){
                    dfs(y, x, new_Mat);
                }
            }
        }
        if (DEBUG) display(new_Mat);
        int cnt=0;
        for (int y=0; y<N; y++) {
            for (int x=0; x<M; x++){
                if (new_Mat[y][x]==0) {
                    cnt += 1;
                }
            }
        }
        if (cnt > max_cnt) max_cnt = cnt;
        if (DEBUG) cout << cnt << "(max: " << max_cnt << ")\n";
    } else {
        for (int i=offset; i<emptyPos.size(); i++){
            combiPos.push_back(emptyPos[i]);
            combi(n, r, i+1, combiPos, emptyPos, ori_Mat);
            combiPos.pop_back();
        }
    }
}
int main() {
    if (RELEASE) ios::sync_with_stdio(false);
    if (RELEASE) cin.tie(NULL);
    
    cin >> N >> M;
    vector<vector<int>> ori_Mat(N, vector<int>(M));
    vector<pos> emptyPos;
    vector<pos> combiPos;
    for (int y=0; y<N; y++){
        for (int x=0; x<M; x++){
            cin >> ori_Mat[y][x];
            if (ori_Mat[y][x] == 0) emptyPos.push_back({y, x});
        }
    }

    if (DEBUG) display(ori_Mat);

    // nCr n: emptyPos.size(), r:3
    combi(emptyPos.size(), 3, 0, combiPos, emptyPos, ori_Mat);

    cout << max_cnt << "\n";
    return 0;
}