//
// Created by p41nt on 21/5/22.
//
#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve() {
    pair<int, int> p1, p2;
    cin >> p1.first >> p1.second >> p2.first >> p2.second;

    if (p1 > p2) swap(p1, p2);

    if (p1.second >= p2.first)
        cout << p2.first << endl;
    else
        cout << p2.first + p1.first << endl;
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
