#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define int long long int

int32_t main() {
    int n, e, t, h;
    cin >> n >> e >> t >> h;
    int a, b, c;

    vector<vector<pair<int, int>>> G(n + 1);

    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq1;

    vector<int> dist(n, INT_MAX);
    vector<int> dist1(n, INT_MAX);
    dist[t] = 0;
    dist1[h] = 0;
    pq.push({0, t});
    pq1.push({0, h});

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();
        if (dist[current.second] != current.first) continue;
        for (auto childnode : G[current.second]) {
            if (dist[current.second] + childnode.second <
                dist[childnode.first]) {
                dist[childnode.first] = dist[current.second] + childnode.second;
                pq.push({dist[childnode.first], childnode.first});
            }
        }
    }

    while (!pq1.empty()) {
        auto current = pq1.top();
        pq1.pop();
        if (dist1[current.second] != current.first) continue;
        for (auto childnode : G[current.second]) {
            if (dist1[current.second] + childnode.second <
                dist1[childnode.first]) {
                dist1[childnode.first] =
                    dist1[current.second] + childnode.second;
                pq1.push({dist1[childnode.first], childnode.first});
            }
        }
    }

    if (dist[h] == INT_MAX || dist1[t] == INT_MAX)
        cout << "-1" << endl;
    else
        cout << dist[h] + dist1[t] << endl;
}
