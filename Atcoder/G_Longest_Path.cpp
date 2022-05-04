#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 100005;

vector<vector<int>> G(maxn);
vector<int> visited(maxn);
vector<int> toposort;
vector<int> dp(maxn);

void dfs(int i) {
    if (visited[i] == 1 || visited[i] == 2)
        return;
    visited[i] = 1;
    for (auto p : G[i]) {
        dfs(p);
    }

    visited[i] = 2;
    toposort.push_back(i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    G.resize(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
    }

    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;

        dfs(i);
    }
    visited.clear();

    reverse(toposort.begin(), toposort.end());

    for (int i = 0; i < n; i++) {
        int k = toposort[i];
        for (auto l : G[k]) {
            dp[l] = max(dp[l], 1 + dp[k]);
        }
    }

    int ans = *max_element(dp.begin(), dp.begin() + n);

    cout << ans << endl;
}
