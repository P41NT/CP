//
// Created by p41nt on 23/5/22.
//

#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve() {
    int n;
    cin >> n;
    int maxa = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        maxa = max(maxa, x);
    }

    cin >> n;

    int maxb = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        maxb = max(maxb, x);
    }

    if (maxa > maxb) {
        cout << "Alice\nAlice\n";
    } else if (maxb > maxa) {
        cout << "Bob\nBob\n";
    } else {
        cout << "Alice\nBob\n";
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