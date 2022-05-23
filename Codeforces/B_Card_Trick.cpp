//
// Created by p41nt on 23/5/22.
//
#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve() {
    int n, m;

    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> m;
    int topmost = 0;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        topmost += x;
        topmost %= n;
    }

    cout << arr[topmost] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("../Current/input.txt", "r", stdin);
    freopen("../Current/output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}