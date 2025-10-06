#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int total = 0;
int flag = 0;

void dfs(int n, int r, int offset, vector<int>& arr, vector<int>& dwfs){
    if (flag) return;
    if (arr.size()==r){
        int sum=0;
        for (int i=0; i<r; i++) {
            sum+=arr[i];
        }
        // cout << "=" << sum << "\n";
        if (total-sum==100) {
            sort(dwfs.begin(), dwfs.end());
            for (int i=0; i<n; i++) {
                if (arr[0] != dwfs[i] && arr[1] != dwfs[i]){
                    cout << dwfs[i] << "\n";
                }
            }
            flag = 1;
        }
    } else {
        for (int i=offset; i<9; i++){
            arr.push_back(dwfs[i]);
            dfs(n, r, i+1, arr, dwfs);
            arr.pop_back();
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> Dwfs(9);
    
    for (int i=0; i<9; i++){
        cin >> Dwfs[i];
        total+=Dwfs[i];
    }
    sort(Dwfs.begin(), Dwfs.end());
    vector<int> Arr;
    dfs(9,2,0,Arr,Dwfs);

    // for (int i=0; i<9; i++) {
    //     for (int j=i+1; j<9; j++) {
    //         int sum = Dwfs[i] + Dwfs[j];
    //         if (total - sum == 100) {
    //             for (int k=0; k<9; k++) {
    //                 int el1 = Dwfs[i];
    //                 int el2 = Dwfs[j];
    //                 if (Dwfs[k] != el1 && Dwfs[k] != el2){
    //                     cout << Dwfs[k] << "\n";
    //                 }
    //             }
    //         }
    //     }
    // }
    return 0;
}