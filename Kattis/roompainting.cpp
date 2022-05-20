//
// Created by p41nt on 18/5/22.
//
#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    vector<int> required(m);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> required[i];
    }

    sort(arr.begin(), arr.end());
    sort(required.begin(), required.end());

    int ans = 0;
    for (auto s : required) {
        ans += (*lower_bound(arr.begin(), arr.end(), s)) - s;
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
}
