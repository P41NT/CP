//
// Created by p41nt on 23/5/22.
//

#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve() {
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first.first;
        arr[i].second = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first.second;
    }

    sort(arr.begin(), arr.end());

    vector<bool> vis(n, false);

    bool possible = true;
    for (int i = 1; i < n; i++) {
        if (arr[i].first.second < arr[i - 1].first.second) possible = false;
    }
    if (!possible)
        cout << "-1\n";
    else {
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++) {
            if (vis[i] || arr[i].second == i) continue;

            int j = i;
            while (!vis[j]) {
                vis[j] = true;
                if (!vis[arr[j].second]) ans.push_back({j, arr[j].second});
                j = arr[j].second;
            }
        }

        cout << ans.size() << endl;
        for (auto s : ans) {
            cout << s.first + 1 << " " << s.second + 1 << endl;
        }
    }
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