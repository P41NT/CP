//
// Created by p41nt on 9/5/22.
//
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    vector<bool> leaf(n + 1, true);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        leaf[arr[i]] = false;
    }

    if (n == 1) {
        cout << "1\n1\n1\n\n";
        return;
    }

    vector<vector<int>> paths;
    vector<bool> used(n + 1);

    for (int i = 1; i <= n; i++) {
        if (!leaf[i]) continue;

        used[i] = true;
        paths.push_back({i});

        int curr = i;

        while (arr[curr] != curr && !used[arr[curr]]) {
            curr = arr[curr];
            used[curr] = true;
            paths[paths.size() - 1].push_back(curr);
        }
    }

    cout << paths.size() << endl;

    for (auto &path : paths) {
        if (path.empty()) continue;
        cout << path.size() << endl;

        reverse(path.begin(), path.end());

        for (int el : path) cout << el << " ";
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
}
