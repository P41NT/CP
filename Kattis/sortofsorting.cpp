//
// Created by p41nt on 24/5/22.
//

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

inline bool cmp(string a, string b) { return a.substr(0, 2) < b.substr(0, 2); }

void solve(int n) {
    // code goes here

    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    stable_sort(arr.begin(), arr.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
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

    //================================================================
    int t;
    t = 1;
    // cin>>t;
    while (cin >> t) {
        if (!t) break;
        solve(t);
    }
    //================================================================

    return 0;
}
