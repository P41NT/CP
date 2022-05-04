#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl "\n"

vector<int> areas;
int colorareas[2];

vector<vector<int>> G;

vector<bool> visited;

void dfs(int i, int color) {
    colorareas[color] += areas[i];
    visited[i] = true;

    for (int cnode : G[i]) {
        if (visited[cnode]) continue;
        dfs(cnode, color ? 0 : 1);
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;

    areas.resize(n + 1);
    visited.resize(n + 1);
    G.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> areas[i];
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        colorareas[0] = colorareas[1] = 0;
        dfs(i, 0);
        ans += min(colorareas[0], colorareas[1]);
    }

    cout << ans << endl;
}
