#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve(int n) {
    vector<string> ans(n + 1);

    int current = -1;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;

        int k = b.length();

        while (k) {
            current = (current + 1) % n;
            if (ans[current] == "") k--;
        }

        ans[current] = a;
    }

    cout << ans[0];
    for (int i = 1; i < n; i++) cout << " " << ans[i];
    cout << endl;
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
    while (cin >> t && t) {
        solve(t);
    }
}
//
// Created by p41nt on 23/5/22.
//
