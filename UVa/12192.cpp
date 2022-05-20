//
// Created by p41nt on 16/5/22.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) return 0;
        vector<vector<int>> arr(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }

        int q;
        cin >> q;

        while (q--) {
            int a, b;
            cin >> a >> b;

            int ans = 0;
            for (int i = 0; i < n; i++) {
                auto starting =
                    lower_bound(arr[i].begin(), arr[i].begin() + m, a) -
                    arr[i].begin();

                for (int size = ans; size < n; size++) {
                    if (i + size >= n) break;
                    if (starting + size >= m) break;
                    if (arr[i + size][starting + size] > b) break;

                    ans = max(ans, size + 1);
                }
            }
            cout << (ans) << '\n';
        }
        cout << "-\n";
    }
}
