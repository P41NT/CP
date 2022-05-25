//
// Created by p41nt on 24/5/22.
//
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve() {
    // code goes here
    int n, m;
    cin >> n >> m;

    vector<vector<char>> arr(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int partitions = 1;

    for (int j = 0; j < m; j++) {
        bool clear = true;
        for (int i = 0; i < n; i++) {
            if (arr[i][j] == '$') clear = false;
        }
        if (clear) partitions++;
    }

    cout << partitions << endl;
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
    // cin>>t;
    while (t--) {
        solve();
    }
    //================================================================

    return 0;
}
