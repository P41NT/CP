//
// Created by p41nt on 24/5/22.
//
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < n; i += 2) {
        if (s[i] != s[i + 1]) ans++;
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("../Current/input.txt", "r", stdin);
    freopen("../Current/output.txt", "w", stdout);
#endif

    //================================================================
    int t;
    t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    //================================================================

    return 0;
}
