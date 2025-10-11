#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;
#define DEBUG 1

struct Node {
    int y, x, cost;
};

vector<int> dy = {-1, 0, 1, 0};
vector<int> dx = { 0, 1, 0,-1};

int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // N=2;
    // M=25;
    cin >> N >> M;
    vector<string> Mat(N);
    for (int i=0; i<N; i++) {
        cin >> Mat[i];
    }
    // ={
    //     "1011101110111011101110111",
    //     "1110111011101110111011101"
    // };

    // if (DEBUG) {
    //     for (auto row : Mat) {
    //         cout << row << "\n";
    //     }
    // };

    deque<Node> q;
    Node start = {0, 0, 1};
    q.push_back(start);

    while(q.size()) {
        Node node = q.front();
        q.pop_front();
        Mat[node.y][node.x] = '2';
        if (node.y == N-1 && node.x == M-1) {
            cout << node.cost << "\n";
            break;
        }
        for (int i=0; i<4; i++){
            int ny = node.y + dy[i];
            int nx = node.x + dx[i];
            if (N > ny && ny >= 0 && M > nx && nx >= 0) {
                if (Mat[ny][nx] == '1') {
                    q.push_back({ny, nx, node.cost+1});
                    Mat[ny][nx] = '2';
                }
            }
        }
    }

    return 0;
}