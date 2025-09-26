#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define DEBUG 0

int main(){
    // int N = 5;
    // int M = 2;
    // int J = 3;
    // vector<int> P = {1, 5, 3};

    int N, M, J;
    cin >> N >> M;
    cin >> J;
    vector<int> P;
    for (int i=0; i<J; i++){
        int tmp;
        cin >> tmp;
        P.push_back(tmp);
    }

    int width_M = M;
    int pos_M = 1;
    auto area_M = [](int p, int m){
        vector <int> area;
        for (int i = p; i < p+m; i++){
            area.push_back(i);
        }
        return area;
    };
    int valid_Pos = N - M + 1;

    if (DEBUG) cout << "\n";
    if (DEBUG) {
        cout << "( ";
        for (auto el : area_M(1,M))
            cout << el << " ";
        cout << ") ";
        cout << valid_Pos << "\n";

        cout << "( ";
        for (auto el : area_M(2,M))
            cout << el << " ";
        cout << ") ";
        cout << valid_Pos << "\n";
    }

    int ret = 0;
    if (valid_Pos == 1){
        cout << ret;
    } else {
        for (auto p : P){
            auto current_M = area_M(pos_M, M);
            if (find(current_M.begin(), current_M.end(), p) != current_M.end()){

            } else {
                if (p > current_M.back()) {
                    int dist = p - current_M.back();
                    pos_M += dist;
                    ret += dist;
                } else if (p < current_M.front()) {
                    int dist = p - current_M.front();
                    pos_M += dist;
                    ret += (-1 * dist);
                }
            }
        }
    }
    cout << ret;
    return 0;
}