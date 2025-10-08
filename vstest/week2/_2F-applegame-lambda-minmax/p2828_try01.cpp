

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct loc{
    int x;
    int w;
};
int N, M, J;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // N=5;
    // M=2;
    // J=3;
    cin >> N >> M;
    cin >> J;

    vector<int> Map(N); for (int i=0,v=1;i<N;i++,v++) Map[i]=v;
    vector<int> A(J); for (int i=0; i<J; i++){cin >> A[i];};
// N 01234
//   -----
//   M
    loc L={1, M};
    vector<int> cL(M);
    auto update_cL = [](loc l, vector<int>& cl) {for (int j=0,i=l.x; i<l.x+l.w; j++,i++) cl[j]=i;};
    update_cL(L, cL);
    auto calc_distance = [](int min, int max, int a) {
        if (a > max) return a-max;
        if (a < min) return a-min;
        return 0;
    };
    // cout << "\n";
    // cout << "\n";
    int ret=0;
    for (int i=0; i<A.size(); i++) {
        int apple = A[i];
        pair minmax = {*min_element(cL.begin(), cL.end()), *max_element(cL.begin(), cL.end())};

        int move=0;
        if (minmax.second >= apple && apple >= minmax.first) move=0;
        else move=1;
        int d=0;
        if (move) d=calc_distance(minmax.first, minmax.second, apple);
        L.x=L.x+d;
        update_cL(L, cL);

        ret += (d < 0) ? -1 * d : d;

        // cout << A[i] << ": ";
        // for (auto el : cL) cout << el << " ";
        // cout << " : " << d;
        // cout << "\n";
    }
    cout << ret << "\n";

    return 0;
}