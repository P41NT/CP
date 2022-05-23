//
// Created by p41nt on 23/5/22.
//
#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve() {
    int n, m;
    cin >> n >> m;

    int threads = 0;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] - arr[i - threads] < 1000) threads++;
    }

    cout << (threads + m - 1) / m << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("../Current/input.txt", "r", stdin);
    freopen("../Current/output.txt", "w", stdout);
#endif

    int t = 1;
    //        cin >> t;
    while (t--) {
        solve();
    }
}
