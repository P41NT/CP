//
// Created by p41nt on 21/5/22.
//

#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> arr(n, vector<char>(m));

    int minx = LONG_MAX, miny = LONG_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'R') {
                minx = min(minx, i);
                miny = min(miny, j);
            }
        }
    }

    if (arr[minx][miny] == 'R')
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
    cin >> t;
    while (t--) {
        solve();
    }
}
