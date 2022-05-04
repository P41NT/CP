#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> G(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    vector<int> solution(n + 1, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    pq.push({0, 1});
    solution[1] = 0;

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        if (curr.first != solution[curr.second]) continue;

        for (auto s : G[curr.second]) {
            if (solution[s.first] > max(curr.first, s.second)) {
                solution[s.first] = max(curr.first, s.second);
                pq.push({solution[s.first], s.first});
            }
        }
    }
    cout << solution[n] << endl;
}
