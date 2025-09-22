#include <iostream>

using namespace std;
typedef long long ll;

int go(ll a, ll b, ll c) {
    if (b == 1) {
        return a % c;
    } else {
        ll el = go(a, b/2, c);
        // el = el % c;
        el = (el * el) % c;
        if (b % 2) el = (el * a) % c;
        return el;
    }
}

int main() {
    ll A, B, C;
    cin >> A >> B >> C;
    ll ans = go(A, B, C);
    cout << ans;
    return 0;
}