#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> G(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    vector<int> dist(n + 1, INT_MAX);
    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        if (dist[curr.second] != curr.first) continue;

        for (auto cnode : G[curr.second]) {
            if (curr.first + cnode.second < dist[cnode.first]) {
                dist[cnode.first] = curr.first + cnode.second;
                pq.push({dist[cnode.first], cnode.first});
            }
        }
    }

    if (dist[n] == INT_MAX)
        cout << -1 << endl;
    else
        cout << dist[n] << endl;
}
