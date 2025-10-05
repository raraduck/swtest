#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
#define DEBUG 0

int N;
vector<string> ret;
// vector<vector<int>> IMG;

void display(int Y, int X, int W, vector<vector<int>>& img){
    cout << ">>>\n";
    for(int y=Y; y<Y+W; y++){
        for (int x=X; x<X+W; x++){
            cout << img[y][x];
        }
        cout << "\n";
    }
    cout << "<<<\n";
}

map<int, int> check_solid(int Y, int X, int W, vector<vector<int>>& img){
    map <int, int> counter;
    for (int y = Y; y<Y+W; y++){
        for (int x = X; x<X+W; x++){
            counter[img[y][x]] += 1;
        }
    }
    return counter;
}

void dfs(int Y, int X, int W, vector<vector<int>>& img){
    
    if (DEBUG) display(Y, X, W, img);
    map<int,int> ckr = check_solid(Y, X, W, img);
    if (ckr[0] == 0 || ckr[1] == 0) {
        if (ckr[0]==0) ret.push_back("1");
        if (ckr[1]==0) ret.push_back("0");
    } else {
        ret.push_back("(");
        // (y,x,w)
        // 좌상단 (Y,    X,     W/2)
        dfs(Y,    X,     W/2, img);
        // 우상단 (Y,    X+W/2, W/2)
        dfs(Y,    X+W/2, W/2, img);
        // 좌하단 (Y+W/2,X,     W/2)
        dfs(Y+W/2,X,     W/2, img);
        // 우하단 (Y+W/2,X+W/2, W/2)
        dfs(Y+W/2,X+W/2, W/2, img);
        ret.push_back(")");
    }
    return;
}

int main() {
    // N = 8;
    // IMG = {
    //     {1,1,1,1,0,0,0,0},
    //     {1,1,1,1,0,0,0,0},
    //     {0,0,0,1,1,1,0,0},
    //     {0,0,0,1,1,1,0,0},
    //     {1,1,1,1,0,0,0,0},
    //     {1,1,1,1,0,0,0,0},
    //     {1,1,1,1,0,0,1,1},
    //     {1,1,1,1,0,0,1,1}
    // };
    cin >> N;
    vector<vector<int>> IMG(N,vector<int>(N));
    for (int y=0; y<N; y++){
        string row;
        cin >> row;
        for (int x=0; x<N; x++){
            IMG[y][x]=row[x]-'0';
        }
    }
    int sY = 0;
    int sX = 0;
    int wY = N;
    int wX = N;
    // ret.push_back("(");
    dfs(sY, sX, N, IMG);
    // ret.push_back(")");
    for (int i =0; i<ret.size(); i++) {
        cout << ret[i];
    };
    cout << "\n";
    return 0;
}