//
// Created by p41nt on 15/5/22.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> lnk;
vector<int> ans;
vector<vector<pair<int, int>>> G;

int root(int x) {
    if (lnk[x] == x) return x;
    return lnk[x] = root(lnk[x]);
}

void unite(int a, int b, int weight) {
    int x = root(a);
    int y = root(b);

    if (x == y) return;

    G[a].push_back({b, weight});
    G[b].push_back({a, weight});
    lnk[y] = x;
}

void dfs(int i, int parent) {
    for (auto cnode : G[i]) {
        if (cnode.first == parent) continue;
        ans[cnode.first] = min(ans[i], cnode.second);
        dfs(cnode.first, i);
    }
}

int n, m, q;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> q;

    lnk.resize(n + 1);

    for (int i = 1; i <= n; i++) lnk[i] = i;

    G.resize(n + 1);
    ans.resize(n + 1);

    vector<pair<int, pair<int, int>>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {c, {a, b}};
    }

    sort(edges.begin(), edges.end(), greater<pair<int, pair<int, int>>>());

    for (int i = 0; i < m; i++) {
        unite(edges[i].second.first, edges[i].second.second, edges[i].first);
    }
    ans[1] = INT_MAX;

    dfs(1, -1);

    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        cout << ans[k] << '\n';
    }
}
