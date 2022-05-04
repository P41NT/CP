#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (G[i].size() == 0) {
            cout << endl;
            continue;
        }
        for (int j = 0; j < G[i].size(); j++) {
            cout << G[i][j];
            if (j == G[i].size() - 1 && i != n)
                cout << endl;
            else if (j < G[i].size() - 1)
                cout << " ";
        }
    }
}
