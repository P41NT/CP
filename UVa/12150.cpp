#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve(int n) {
    vector<int> solution(n, -1);

    bool possible = true;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (i + b < 0) possible = false;
        if (i + b >= n) possible = false;
        if (possible && solution[i + b] != -1) possible = false;
        if (possible) solution[i + b] = a;
        //        cout << i + b << " " << a << endl;
    }

    if (!possible) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << solution[i];
            if (i != n - 1) cout << " ";
        }
        cout << endl;
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
    //        cin >> t;
    while (cin >> t) {
        if (t == 0) return 0;
        solve(t);
    }
}
//
// Created by p41nt on 23/5/22.
//
