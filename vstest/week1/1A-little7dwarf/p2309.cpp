#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace P2309_1 {
    int SUM = 0;
    int N = 9;
    int R = 2;
    vector <int> v;
    int main() {
        int tmp;
        for (int i = 0; i < 9; i++) {
            cin >> tmp;
            v.push_back(tmp);
            SUM += tmp;
        }
        sort(v.begin(), v.end());


        vector <int> b;
        for (int j = 0; j < N; j++) {
            for (int i = j + 1; i < N; i++) {
                tmp = v[j] + v[i];
                if ((SUM - tmp) == 100) {
                    b.push_back(v[i]);
                    b.push_back(v[j]);
                }
            }
        }
        /*for (int item1 : v) {
            bool ready = true;
            for (int item2 : b) {
                if (item1 == item2) {
                    ready = false;
                    break;
                }
            };
            if (ready) cout << item1 << '\n';
        }

        for (int i = 0; i < 9; ++i) {
            if (v[i] == b[0] || v[i] == b[1]) continue;
            cout << v[i] << '\n';
        }*/
        /*for (int item1 : v) {
            int isPass = true;
            for (int item2 : b) {
                if (item1 == item2) {
                    isPass = false;
                }
            }
            if (isPass) cout << item1 << '\n';
        }*/
        for (int item2 : b) {
            auto it = find(v.begin(), v.end(), item2);
            if (it != v.end()) {
                v.erase(it);
            }
        }
        for (int item1 : v) {
            cout << item1 << '\n';
        }
        return 0;
    }
}

namespace P2309_2 {
    int SUM = 0;
    int N = 4;
    int R = 2;
    vector <int> v;
    void makePermutation(int n, int r, int depth) {
        /*for (int el : v) cout << el << ' ';
        cout << '\n';*/
        if (depth == r) {
            int cnt = 0;
            for (int el : v) {
                if (cnt++ >= r) break;
                cout << el << ' ';
            }
            cout << '\n';
            return;
        }
        else {
            for (int i = depth; i < n; i++) {
                swap(v[i], v[depth]);
                makePermutation(n, r, depth + 1);
                swap(v[i], v[depth]);
            }
        }
    }

    void combi(int start, vector<int> b) {
        if (b.size() == R) {
            for (int el : b) cout << el << ' ';
            cout << '\n';
            return;
        }
        else {
            for (int i = start; i < N; i++) {
                b.push_back(v[i]);
                combi(i + 1, b);
                b.pop_back();
            }
        }
    }

    int main() {
        int tmp;
        for (int i = 0; i < N; i++) {
            cin >> tmp;
            v.push_back(tmp);
            SUM += tmp;
        }
        cout << "\n";
        cout << "������ 9��: " << "\n";
        for (int i = 0; i < N; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        cout << "\n";
        //cout << "��ȯ ��" << '\n';
        makePermutation(N, R, 0);
        /*cout << "��ȯ ��" << '\n';
        swap(v[0], v[1]);
        makePermutation(N, R, v);
        cout << "\n";
        cout << "\n";*/

        sort(v.begin(), v.end());
        cout << "������ ����: " << "\n";
        for (int el : v) {
            cout << el << " ";
        }
        cout << "\n";
        cout << "\n";

        cout << "������ ����: " << "\n";
        do {
            for (int el : v) cout << el << ' ';
            cout << '\n';
        } while (next_permutation(v.begin(), v.end()));

        cout << "\n";
        cout << "\n";
        cout << "������ ����: " << "\n";
        for (int y = 0; y < N; y++) {
            for (int x = y + 1; x < N; x++) {
                cout << v[y] << " " << v[x] << '=' << SUM - (v[y] + v[x]) << '\n';
            }
        }

        cout << "\n";
        cout << "\n";
        vector<int> b;
        combi(0, b);

        return 0;
    }
}