#include <iostream>
#include <vector>

using namespace std;

#define int long long int

vector<vector<int>> G;

int dfs(int i) {
    int maxd = 0;
    for (auto s : G[i]) {
        maxd = max(maxd, dfs(s));
    }

    return maxd + 1;
}

int32_t main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    arr[0] = -1;
    for (int i = 1; i < n; i++) {
        cin >> arr[i];
    }

    G.resize(n);

    for (int i = 1; i < n; i++) {
        G[arr[i]].push_back(i);
    }

    int ans = dfs(0);

    cout << ans << endl;
}
