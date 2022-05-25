//
// Created by p41nt on 24/5/22.
//
#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> prefix(n);
    vector<int> suffix(n);

    prefix[0] = arr[0];
    suffix[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++) {
        prefix[i] = max(arr[i], prefix[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = min(arr[i], suffix[i + 1]);
    }

    int counter = 0;
    for (int i = 0; i < n; i++)
        if (prefix[i] == suffix[i] && prefix[i] == arr[i]) counter++;

    cout << counter << endl;
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
    //    cin >> t;
    while (t--) {
        solve();
    }
}
