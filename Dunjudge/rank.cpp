#include <bits/stdc++.h>

using namespace std;

vector<int> solution;

vector<vector<int>> G;
vector<int> visited;

bool dag = true;

void dfs(int i) {
    visited[i] = 1;
    for (auto s : G[i]) {
        if (visited[s] == 0)
            dfs(s);
        else if (visited[s] == 1)
            dag = false;
    }
    solution.push_back(i);
    visited[i] = 2;
}

int main() {
    int n, v;
    cin >> n >> v;

    G.resize(n + 1);

    int temp1, temp2, temp3;
    char c1, c2;
    for (int i = 0; i < v; i++) {
        cin >> temp1 >> c1 >> temp2 >> c2 >> temp3;

        if (c1 == '>') {
            G[temp1].push_back(temp2);
            G[temp1].push_back(temp3);
        } else {
            G[temp1].push_back(temp3);
            G[temp2].push_back(temp3);
        }
    }

    visited.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i);
    }

    if (dag) {
        reverse(solution.begin(), solution.end());
        for (auto s : solution) cout << s << " ";
        cout << endl;
    } else
        cout << 0 << endl;
}
