//
// Created by p41nt on 10/5/22.
//
#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> arr;
vector<int> val;
vector<vector<int>> G(n);
string colors;

void dfs(int i, int parent) {
    int counter = ((colors[i - 1] == 'B') ? -1 : 1);

    for (auto cnode : G[i]) {
        if (cnode == parent) continue;
        dfs(cnode, i);
        counter += val[cnode];
    }
    val[i] = counter;
}

void solve() {
    cin >> n;

    arr.clear();
    val.clear();
    for (auto &x : G) {
        x.clear();
    }

    arr.resize(n + 1);
    val.resize(n + 1);
    G.resize(n + 1);

    arr[0] = -1;

    for (int i = 2; i <= n; i++) {
        cin >> arr[i];
        G[arr[i]].push_back(i);
    }

    cin >> colors;

    dfs(1, -1);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (val[i] == 0) ans++;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
