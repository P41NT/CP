#include <bits/stdc++.h>

using namespace std;

#define int long long int

string answer(int n, int m, int k) {
    if (m > n * (n - 1) / 2 || m < (n - 1)) return "NO";
    if (k <= 1) return "NO";
    if (k == 2) {
        if (n == 1) return "YES";
        else return "NO";
    }
    if (k == 3) {
        //cout<< n * (n-1) / 2<<endl;
        if (m == n * (n - 1) / 2) return "YES";
        else return "NO";
    }
    return "YES";
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    cout << answer(n, m, k) << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}