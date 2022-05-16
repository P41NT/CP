//
// Created by p41nt on 10/5/22.
//

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> lastposition(n + 1, -1);
    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (lastposition[arr[i]] != -1) {
            ans = min(ans, i - lastposition[arr[i]] + 1);
        }
        lastposition[arr[i]] = i;
    }

    if (ans == INT_MAX)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
