#include <iostream>
#include <vector>

using namespace std;

#define DEBUG 0
#define RELEASE 1

vector<int> dy={-1, 0, 1, 0};
vector<int> dx={0, 1, 0, -1};
int N, L, R, SUM, CNT, RET;
vector<vector<int>> Nations;
struct pos {
    int y, x;
};

void display(vector<vector<int>>& arr) {
    cout << "<<<\n";
    for (int y=0; y<N; y++){
        for (int x=0; x<N; x++){
            cout << arr[y][x] << " ";
        }
        cout << "\n";
    }
    cout << ">>>\n";
}

bool check(int n0, int n1) {
    int diff = abs(n0-n1);
    return ( R >= diff ) && ( diff >= L);
}
void dfs(int y, int x, vector<vector<int>>& visited, vector<pos>& con_com){
    visited[y][x]=1;
    SUM+=Nations[y][x];
    con_com.push_back({y, x});
    for (int i=0; i<4; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if (N>ny && ny>=0 && N>nx && nx>=0){
            if (visited[ny][nx] == 0) {
                if (check(Nations[y][x], Nations[ny][nx])){
                    dfs(ny,nx,visited,con_com);
                }
            }
        }
    }
}
int main() {
    if (RELEASE) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
    }

    cin >> N >> L >> R;
    Nations=vector<vector<int>>(N, vector<int>(N));
    vector<vector<int>> Visited(N, vector<int>(N, 0));
    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            cin >> Nations[y][x];
        }
    }
    int flag = 1;

    while(true){
        flag = 1;
        if (DEBUG) display(Nations);
        for (auto& row : Visited) fill(row.begin(), row.end(), 0);
        for (int y=0; y<N; y++){
            for (int x=0; x<N; x++){
                if (Visited[y][x]==0){
                    SUM=0;
                    vector<pos> Connected_compoment;
                    dfs(y, x, Visited, Connected_compoment);
                    int AVG = SUM / Connected_compoment.size();
                    for (auto p : Connected_compoment){
                        Nations[p.y][p.x] = AVG;
                    }
                    if (DEBUG) display(Nations);
                    if (DEBUG) display(Visited);
                    if (Connected_compoment.size() != 1) {
                        flag = 0;
                    }
                    if (DEBUG) cout << "FLAG: " << flag << " ";
                    if (DEBUG) cout << "CNT: " << CNT << " ";
                    if (DEBUG) cout << "SUM: " << SUM << " ";
                    if (DEBUG) cout << "SIZE: " << Connected_compoment.size() << " ";
                    if (DEBUG) cout << "AVG: " << AVG << "\n";
                }
            }
        }
        if (flag == 1) {
            break;
        }
        CNT += 1;
    }
    cout << CNT << "\n";

    return 0;
}