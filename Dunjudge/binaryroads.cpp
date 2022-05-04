#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> G(n);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(2));
    vector<vector<int>> dist(n, vector<int>(2, LONG_LONG_MAX));

    dist[0][0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        if (visited[curr.first][curr.second]) continue;
        visited[curr.first][curr.second] = true;

        for (auto s : G[curr.first]) {
            if (s.second != curr.second) continue;
            if (visited[s.first][(curr.second ^ 1)]) continue;
            dist[s.first][curr.second ^ 1] = dist[curr.first][curr.second] + 1;
            q.push({s.first, curr.second ^ 1});
        }
    }

    int ans = min(dist[n - 1][0], dist[n - 1][1]);

    for (int i = 0; i < 2; i++) {
        fill(visited[i].begin(), visited[i].end(), false);
        fill(dist[i].begin(), dist[i].end(), LONG_LONG_MAX);
    }

    dist[0][1] = 0;
    q.push({0, 1});

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        if (visited[curr.first][curr.second]) continue;
        visited[curr.first][curr.second] = true;

        for (auto s : G[curr.first]) {
            if (s.second != curr.second) continue;
            if (visited[s.first][(curr.second ^ 1)]) continue;
            dist[s.first][curr.second ^ 1] = dist[curr.first][curr.second] + 1;
            q.push({s.first, curr.second ^ 1});
        }
    }

    ans = min(ans, min(dist[n - 1][0], dist[n - 1][1]));

    cout << (ans == LONG_LONG_MAX ? -1 : ans) << endl;
}
