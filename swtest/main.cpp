#include <iostream>
#include <vector>
using namespace std;

int MAT[9] = {};
vector<int> v;
int main() {
    for (int i = 0; i < 9; i++) {
        cin >> MAT[i];
        v.push_back(MAT[i]);
    }
    cout << "\n";
    cout << "������ 9��: " << "\n";
    for (int i = 0; i < 9; i++) {
        cout << "(" << MAT[i] << ", " << v[i] << ") ";
    }
    cout << "\n";


    return 0;
}