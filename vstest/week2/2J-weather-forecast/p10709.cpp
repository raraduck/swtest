#include <iostream>
#include <vector>

// 3 4
// c..c
// ..c.
// ....

using namespace std;

int H, W;

void tick_cmap(vector<vector<char>>& cmap) {
    for (int x=W-1; x>=0; x--){
        for (int y=0; y<H; y++){
            if (x==0) {
                cmap[y][x]='.';
            } else {
                cmap[y][x]=cmap[y][x-1];
            }
        }
    }
}

void update_imap(int t, vector<vector<char>>& cmap, vector<vector<int>>& imap){
    for (int y=0; y<H; y++){
        for (int x=0; x<W; x++){
            if (imap[y][x] == -1){
                if (cmap[y][x]=='c') imap[y][x]=t;
            }
        }
    }
}

template <typename T>
void display_map(vector<vector<T>>& map){
    // cout << ">>>\n";
    for (int y=0; y<H; y++) {
        for (int x=0; x<W; x++){
            cout << map[y][x] << " ";
        }
        cout << "\n";
    }
    // cout << "<<<\n";
}

int main() {
    cin >> H >> W;
    vector<vector<int>> iMap(H, vector<int>(W, -1));
    vector<vector<char>> cMap(H, vector<char>(W));
    for (int y=0; y<H; y++) {
        string tmp;
        cin >> tmp;
        for (int x=0; x<W; x++) {
            cMap[y][x]=tmp[x];
        }
    }
    // cMap={
    //     {'c','.','.','c'},
    //     {'.','.','c','.'},
    //     {'.','.','.','.'}
    // };

    // t=0
    update_imap(0, cMap, iMap);
    // display_map(iMap);

    for (int t=1; t<W; t++){
        tick_cmap(cMap);
        update_imap(t, cMap, iMap);
        // display_map(iMap);
    }
    display_map(iMap);

    // t=1
    // update_imap(cMap, iMap);
    // display_map(cMap);

    return 0;
}