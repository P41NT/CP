#include <bits/stdc++.h>

using namespace std;

#define int long long int

int32_t main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> G(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, -c});
    }

    queue<int> q;
    vector<int> dist(n + 1);
    vector<bool> visited(n + 1);

    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (visited[curr]) continue;
        visited[curr] = true;

        for (auto s : G[curr]) {
            dist[s.first] = dist[curr] + s.second;
            q.push(s.first);
        }
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;

        cout << dist[y] - dist[x] << endl;
    }
}
