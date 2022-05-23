//
// Created by p41nt on 23/5/22.
//

#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve(int n) {
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> taken(n, -1);

    for (int i = 1; i < n; i++) {
        taken[abs(arr[i] - arr[i - 1])] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (taken[i] == -1) {
            cout << "Not Jolly" << endl;
            return;
        }
    }
    cout << "Jolly" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("../Current/input.txt", "r", stdin);
    freopen("../Current/output.txt", "w", stdout);
#endif

    int n;
    //    cin >> t;
    while (cin >> n) {
        solve(n);
    }
}
