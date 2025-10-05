#include <iostream>

using namespace std;

typedef long long ll;

ll mod_pow(ll a, ll b, ll c){
    if (b == 1) { // 기저값 or 기저조건
        return a % c;
    } else {
        ll half = mod_pow(a, b/2, c);
        half = (half * half) % c;
        if (b % 2) half = (half * a) % c;
        return half;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int A, B, C;
    cin >> A >> B >> C;
    ll Ans = mod_pow(A, B, C);
    cout << Ans;
    return 0;
}