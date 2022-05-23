//
// Created by p41nt on 20/5/22.
//

#include <bits/stdc++.h>

using namespace std;

#define int long long int

int n, m;
void solve() {
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<int>> sorted(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            sorted[i][j] = arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        sort(sorted[i].begin(), sorted[i].end());
    }
    int start = -1;
    int end = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != sorted[i][j]) {
                if (start == -1)
                    start = j;
                else {
                    end = j;
                    break;
                }
            }
        }
        if (end != -1) break;
    }

    if (start == -1) {
        cout << 1 << " " << 1 << endl;
        return;
    }

    bool possible = true;
    for (int i = 0; i < n; i++) {
        swap(arr[i][start], arr[i][end]);
        for (int j = 0; j < m; j++) {
            if (sorted[i][j] != arr[i][j]) {
                cout << -1 << endl;
                return;
            }
        }
    }

    cout << (start + 1) << " " << (end + 1) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("../Current/input", "r", stdin);
    freopen("../Current/output", "w", stdout);
#endif

    //    int t = 1;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}