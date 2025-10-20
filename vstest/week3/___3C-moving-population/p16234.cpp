#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>

using namespace std;

#define DEBUG 0
#define RELEASE 1

vector<int> dy={-1, 0, 1, 0};
vector<int> dx={0, 1, 0, -1};
int N, L, R, CNT, RET;
vector<vector<int>> Nations;
struct pos {
    int y, x, d, p;
};
// deque<pos> dq;

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

bool end_check (int y, int x, vector<vector<int>>& visited) {
    for (int i=0; i<4; i++) {
        int ny=y+dy[i];
        int nx=x+dx[i];
        if (N>ny && ny>=0 && N>nx && nx>=0){
            if (visited[ny][nx]==0){
                if (check(Nations[y][x], Nations[ny][nx])){
                    return false;
                }
            }
        }
    }
    return true;
}
pair<int, int> bfs(int y, int x, vector<vector<int>>& visited) {
    deque<pos> Dq;
    Dq.push_back({y, x, 0, 0});
    visited[y][x] = CNT;
    int sum_of_areas = 0;
    int sum_of_people = 0;
    while(Dq.size()) {
        pos po = Dq.front();
        Dq.pop_front();
        int y = po.y;
        int x = po.x;
        int d = po.d;
        int p = po.p;
        bool is_end = end_check(y, x, visited);
        if (is_end) {
            if (DEBUG) display(visited);
            sum_of_areas += d;
            sum_of_people += p;
            continue;
        }
        for (int i=0; i<4; i++) {
            int ny=y+dy[i];
            int nx=x+dx[i];
            if (N>ny && ny>=0 && N>nx && nx>=0){
                if (visited[ny][nx]==0){
                    if (check(Nations[y][x], Nations[ny][nx])){
                        pos npo = {y+dy[i], x+dx[i], d+1, p+Nations[ny][nx]};
                        visited[ny][nx]=CNT;
                        Dq.push_back(npo);
                    }
                }
            }
        }
    }
    return {sum_of_areas, sum_of_people};
}
int main() {
    if (RELEASE) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
    }

    cin >> N >> L >> R;
    Nations=vector<vector<int>>(N, vector<int>(N));
    vector<vector<int>> Visited(N, vector<int>(N,0));
    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            cin >> Nations[y][x];
        }
    }

    int flag=1;
    while(true){
        flag=1;
        CNT=0;
        for(auto& row:Visited) fill(row.begin(), row.end(), 0);
        cout << ":::::::::::RESET ALL(" << ++RET << "):::::::::::\n";
        if (DEBUG) display(Nations);

        for (int y=0; y<N; y++) {
            for (int x=0; x<N; x++) {
                if (Visited[y][x] == 0) {
                    CNT++;
                    pair<int, int> area_people=bfs(y, x, Visited);
                    area_people.first += 1;
                    area_people.second += Nations[y][x];
                    int avg_people = area_people.second/area_people.first;
                    for (int yy=0; yy<N; yy++){
                        for (int xx=0; xx<N; xx++){
                            if (Visited[yy][xx]==CNT) {
                                Nations[yy][xx] = avg_people;
                            }
                        }
                    }
                    if (DEBUG) display(Nations);
                    if (area_people.first != 1) {
                        flag=0;
                    }
                    if (DEBUG) cout << "AREA at " << RET << ": " << area_people.first << ", " << area_people.second << ", " << avg_people << "\n";
                }
            }
        }

        if (flag) break;
    }
    cout << RET - 1 << "\n";
    return 0;
}