#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;
#define DEBUG 0
#define RELEASE 1

vector<int> dy={-1, 0, 1, 0};
vector<int> dx={0, 1, 0, -1};
struct pos {
    int y;
    int x;
};
struct paired{
    int min_dist;
    pos t0;
    pos t1;
};
int N, M;
vector<pos> pLand;
vector<vector<int>> mLand;
vector<paired> Paired_scores;
int max_dist=0;
int min_dist;
int dist;

void display(vector<vector<int>>& arr) {
    cout << ">>>\n";
    for (int y=0; y<N; y++) {
        for (int x=0; x<M; x++) {
            cout << arr[y][x] << " ";
        }
        cout << "\n";
    }
    cout << "<<<\n";
}

void dfs(pos t0, pos t1, vector<vector<int>>& visited) {
    // display(visited);
    if (dist >= min_dist) {
        return;
    }
    // if (dist)
    // if (min_dist <= *dist) {
    //     if (max_dist < min_dist) max_dist = min_dist;
    //     return;
    // }
    if (t0.y == t1.y && t0.x == t1.x) {
        if (min_dist > dist) min_dist = dist;
        return;
    }
    for (int i=0; i<4; i++) {
        int ny=t0.y+dy[i];
        int nx=t0.x+dx[i];
        pos nt={ny, nx};
        if (N>ny && ny>=0 && M>nx && nx>=0) {
            if (mLand[ny][nx] == 1 && visited[ny][nx] == 1) {
                visited[ny][nx]=2;
                dist+=1;
                dfs(nt, t1, visited);
                visited[ny][nx]=1;
                dist-=1;
                // *dist-=1;
            }
        }
    }

}

int bfs(pos p, deque<pair<pos, int>>& dq, vector<vector<int>>& visited) {
    visited[p.y][p.x]=2;
    dq.push_back({p, 0});
    int max_d=0;
    while(dq.size()){
        if (DEBUG) display(visited);
        pair<pos, int> ct = dq.front();
        dq.pop_front();
        int y=ct.first.y;
        int x=ct.first.x;
        int d = ct.second;
        if (d > max_d) max_d=d;
        // if (y==t1.y && x==t1.x) {
        //     return d;
        // }
        for (int i=0; i<4; i++) {
            pos nt={y+dy[i], x+dx[i]};
            if (N>nt.y && nt.y>=0 && M>nt.x && nt.x>=0){
                if (visited[nt.y][nt.x]==1){
                    visited[nt.y][nt.x]=2;
                    dq.push_back({nt, d+1});
                    // visited[nt.y][nt.x]=1;
                }
            }
        }
    }
    return max_d;
}

void combi(int n, int r, int offset, vector<pos>& T) {
    if (T.size()==r) {
        vector<vector<int>> Visited = mLand;
        Visited[T[0].y][T[0].x]=2;
        // min_dist=9999;
        // dist=0;

        // dfs(T[0], T[1], Visited);
        // vector<
        deque<pair<pos,int>> Dq;
        // min_dist = bfs(T[0], T[1], Dq, Visited);
        if (min_dist > max_dist) max_dist = min_dist;
        // if (min_dist == 9999) {
        //     return;
        // }
        
        // Paired_scores.push_back({
        //     min_dist,
        //     T[0],
        //     T[1]
        // });
        return;
    }

    for (int i=offset; i<pLand.size(); i++) {
        T.push_back(pLand[i]);
        combi(n, r, i+1, T);
        T.pop_back();
    }
}

int main() {
    if (RELEASE) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
    }

    cin >> N >> M;
    cin.ignore();
    // max_dist=0;
    min_dist=N+M;
    mLand = vector<vector<int>>(N, vector<int>(M, 0));
    for (int y=0; y<N; y++) {
        string tmp;
        getline(cin, tmp);
        for (int x=0; x<M; x++) {
            if (tmp[x]=='L') {
                mLand[y][x]=1;
                // pLand.push_back({y,x});
            } else {
                mLand[y][x]=0;
            }
        }
    }
    
    int ret = 0;
    for (int y=0; y<N; y++) {
        for (int x=0; x<M; x++) {
            if (mLand[y][x] == 1){
                vector<vector<int>> Visited = mLand;
                deque<pair<pos,int>> Dq;
                ret = max(ret, bfs({y, x}, Dq, Visited));
            }
        }
    }
    // min_dist = bfs(T[0], T[1], Dq, Visited);
    // if (min_dist > max_dist) max_dist = min_dist;
    cout << ret;
    return 0;
}