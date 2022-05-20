
#include <bits/stdc++.h>

using namespace std;

#define int long long int

int n, m;

void update(vector<int>& tree, int i, int delta) {
    while (i <= n) {
        tree[i] += delta;
        i += i & -i;
    }
}

int sum(vector<int>& tree, int i) {
    int ret = 0;
    while (i) {
        ret += tree[i];
        i -= i & -i;
    }

    return ret;
}

void solve() {
    cin >> n >> m;
    vector<int> rows(n + 1);
    vector<int> cols(n + 1);

    vector<int> fenwick_rows, fenwick_cols;

    fenwick_rows.assign(n + 1, 0);
    fenwick_cols.assign(n + 1, 0);

    while (m--) {
        int query;
        cin >> query;
        if (query == 1) {
            int x, y;
            cin >> x >> y;
            if (++rows[x] == 1) update(fenwick_rows, x, 1);
            if (++cols[y] == 1) update(fenwick_cols, y, 1);
        } else if (query == 2) {
            int x, y;
            cin >> x >> y;
            if (--rows[x] == 0) update(fenwick_rows, x, -1);
            if (--cols[y] == 0) update(fenwick_cols, y, -1);
        } else {
            //            {
            //                for (int i = 1; i < n; i++) {
            //                    cout << sum(fenwick_rows, i) -
            //                    sum(fenwick_rows, i - 1);
            //                }
            //                cout << endl;
            //                for (int i = 1; i < n; i++) {
            //                    cout << sum(fenwick_cols, i) -
            //                    sum(fenwick_cols, i - 1);
            //                }
            //            }
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int x_sum = sum(fenwick_rows, x2) - sum(fenwick_rows, x1 - 1);
            int y_sum = sum(fenwick_cols, y2) - sum(fenwick_cols, y1 - 1);

            if (x_sum == (x2 - x1 + 1) || y_sum == (y2 - y1 + 1))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("../Current/input.txt", "r", stdin);
    freopen("../Current/output.txt", "w", stdout);
#endif

    int t = 1;
    //    cin >> t;
    while (t--) {
        solve();
    }
}
