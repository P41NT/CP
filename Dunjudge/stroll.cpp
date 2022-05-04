#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> G;

int dfs(int i) {
    if (i == 0) return 0;

    return 1 + max(dfs(G[i].first), dfs(G[i].second));
}

int main() {
    cin >> n;
    G.resize(n + 1);

    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a] = {b, c};
    }

    int ans = dfs(1);

    cout << ans << endl;
}
