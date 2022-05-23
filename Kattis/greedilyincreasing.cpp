#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int current_index = 0;
    int current_value = arr[0];

    vector<int> solution;
    solution.push_back(current_value);

    while (current_index < n) {
        if (arr[current_index] > current_value) {
            current_value = arr[current_index];
            solution.push_back(current_value);
        }
        current_index++;
    }

    cout << solution.size() << endl;
    for (auto s : solution)
        cout << s << " ";

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

    int t = 1;
    //        cin >> t;
    while (t--) {
        solve();
    }
}
//
// Created by p41nt on 23/5/22.
//
