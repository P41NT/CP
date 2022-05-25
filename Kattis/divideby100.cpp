//
// Created by p41nt on 23/5/22.
//
#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve() {
    string s, t;
    cin >> s >> t;

    int n = s.length();
    int m = t.length();

    while (s[n - 1] == '0' && t[m - 1] == '0') {
        s.pop_back();
        t.pop_back();
        n--, m--;
    }

    if (m > n) {
        cout << "0.";
        for (int i = 0; i < m - n - 1; i++) {
            cout << "0";
        }
        cout << s << endl;
    } else {
        if (m == 1)
            cout << s << endl;
        else
            cout << s.substr(0, n - m + 1) << "." << s.substr(n - m + 1)
                 << endl;
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

    int t = 1;
    //    cin >> t;
    while (t--) {
        solve();
    }
}
