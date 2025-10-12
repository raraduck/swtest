#include <iostream>
#include <vector>

using namespace std;
#define DEBUG 0
#define RELEASE 1

struct pos {
    int y;
    int x;
};
struct obj {
    int min_d=9999;
    vector<pos> p;
};
int N, M;
obj opt;
void combi(int n, int r, int offset, vector<pos>& cs, vector<pos>& sel_cs, vector<pos>& hs, vector<vector<int>>& mat){
    if (sel_cs.size()==r) {
        int sum_d = 0;
        for (auto h : hs) {
            int tmp_d=2*N;
            for (auto c : sel_cs){
                if (DEBUG) cout << "From h(" << h.y << "," << h.x << ") " << "To c(" << c.y << "," << c.x << ") = ";
                int dy = c.y - h.y; dy = (dy >= 0) ? dy:-1*dy;
                int dx = c.x - h.x; dx = (dx >= 0) ? dx:-1*dx;
                int d = dy + dx;
                if (d < tmp_d) tmp_d = d;
                if (DEBUG) cout << d << " : " << tmp_d;
            }
            sum_d += tmp_d;
            if (DEBUG) cout << " : " << sum_d << "\n";
        }
        if (DEBUG) cout << "total distance: " << sum_d << "\n";
        if (DEBUG) for (auto c:cs) cout << "(" << c.y << "," << c.x << ")" << " ";
        if (DEBUG) cout << "\n";
        if (sum_d < opt.min_d) {
            opt.min_d = sum_d;
            opt.p = sel_cs;
        }
    } else {
        for (int i=offset; i<cs.size(); i++) {
            sel_cs.push_back(cs[i]);
            combi(n, r, i+1, cs, sel_cs, hs, mat);
            sel_cs.pop_back();
        }
    }
}
int main(){
    if (RELEASE) ios::sync_with_stdio(false);
    if (RELEASE) cin.tie(NULL);

    cin >> N >> M;

    vector<pos> Hs;
    vector<pos> Cs;
    vector<vector<int>> Mat(N, vector<int>(N));
    for (int y=0; y<N; y++){
        for (int x=0; x<N; x++){
            cin >> Mat[y][x];
            if (Mat[y][x] == 2) Cs.push_back({y,x});
            if (Mat[y][x] == 1) Hs.push_back({y,x});
        }
    }

    //1. combi로 Cs 구하기
    vector<pos> Sel_Cs;
    combi(Cs.size(), M, 0, Cs, Sel_Cs, Hs, Mat);
    if (DEBUG){
        cout << opt.min_d << "\n";
        for (auto c:opt.p) cout << "(" << c.y << "," << c.x << ") ";
        cout << "\n";
    }
    cout << opt.min_d << "\n";
    return 0;
}