#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
#define DEBUG 0
// // 좌표 구조체
// struct Point {
//     int x;
//     int y;
// };

// // 두 좌표를 묶는 구조체
// struct Pair {
//     Point p1;
//     Point p2;
// };

// // 4개의 방향을 가지는 구조체
// struct Direction {
//     Pair q1;
//     Pair q2;
//     Pair q3;
//     Pair q4;
// };

struct Point {
    double s, e;
};

using Pair = pair<Point, Point>; // (p1, p2)

// 람다로 direction 함수 정의
auto direction = [](double y, double x, double w) {
    vector<Pair> dirs {
        { {x,     x + w/2}, {y,     y + w/2} },
        { {x+w/2, w/2    }, {y,     y + w/2} },
        { {x,     x + w/2}, {y+w/2, w       } },
        { {x+w/2, w/2    }, {y+w/2, w       } }
    };
    return dirs;
};

void display(int y, int x, int w, const vector<vector<int>>& img) {
    cout << ">>>\n";
    for (int i = y; i < y + w; i++){
        for (int j = x; j < x + w; j++){
            cout << img[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "<<<\n";
}

vector<int> is_solid(int y, int x, int w, const vector<vector<int>>& img) {
    vector <int> arr;
    for (int i = y; i < y + w; i++){
        for (int j = x; j < x + w; j++){
            arr.push_back(img[i][j]);
        }
    }
    return arr;
}

void dfs(int y, int x, int w, vector<vector<int>>& img, vector<string>& acc){
    // vector<int> el_list = is_solid(y, x, w, img);  // ✅ 세미콜론 추가
    // display(y,x,w,img);
    vector<int> el_v = is_solid(y, x, w, img);
    sort(el_v.begin(), el_v.end());
    el_v.erase(unique(el_v.begin(), el_v.end()), el_v.end());
    // set<int> el_s(el_v.begin(), el_v.end());

    // for (auto el : el_s){
    //     cout << el << " ";
    // }
    // cout << "\n";
    if (el_v.size() == 1){
        acc.push_back(to_string(el_v[0]));
        return;
        // return 0;
    } else {
        acc.push_back("(");
        for (auto d : direction(y,x,w)){
            dfs(d.second.s, d.first.s, w/2, img, acc);
        }
        acc.push_back(")");
    }
}

int main() {
    // int N = 8;
    // vector<vector<int>> IMG {
    //     {1,1,1,1,0,0,0,0},
    //     {1,1,1,1,0,0,0,0},
    //     {0,0,0,1,1,1,0,0},
    //     {0,0,0,1,1,1,0,0},
    //     {1,1,1,1,0,0,0,0},
    //     {1,1,1,1,0,0,0,0},
    //     {1,1,1,1,0,0,1,1},
    //     {1,1,1,1,0,0,1,1},
    // };
    int N;
    cin >> N;
    vector<vector<int>> IMG(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;  // "11110000" 같은 문자열로 입력 받음
        for (int j = 0; j < N; j++) {
            IMG[i][j] = row[j] - '0';  // 문자 '1' → 정수 1 변환
        }
    }

    if (DEBUG){
        cout << N << "\n";
        for (auto r : IMG){
            for (auto c : r){
                cout << c << " ";
            }
            cout << "\n";
        }
    }

    // direction direct;
    // direct.q1={ 0,  1,  2,  3};
    // direct.q2={ 4,  5,  6,  7};
    // direct.q3={ 8,  9, 10, 11};
    // direct.q4={12, 13, 14, 15};

    // auto dirs = direction(0, 0, 8);
    // cout << dirs[0].first.x << " " << dirs[0].first.y;

    vector<string> acc;
    dfs(0, 0, N, IMG, acc);
    for (auto el : acc){
        cout << el << "";
    }
    return 0;
}