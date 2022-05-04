#include <limits.h>

#include <iostream>
#include <vector>

#define int long long int
#define endl "\n"

using namespace std;

void update(int index, int left, int right, vector<int>& segtree, int position,
            int value) {
    if (left == right) {
        segtree[index] = value;
        return;
    }

    int mid = (left + right) / 2;
    if (position <= mid) {
        update(index * 2, left, mid, segtree, position, value);
    } else {
        update(index * 2 + 1, mid + 1, right, segtree, position, value);
    }

    segtree[index] = min(segtree[index * 2], segtree[index * 2 + 1]);
}

int query(int index, int left, int right, vector<int>& segtree, int ql,
          int qr) {
    if (left > qr || right < ql) return INT_MAX;
    if (left >= ql && right <= qr) return segtree[index];

    int mid = (left + right) / 2;

    return min(query(index * 2, left, mid, segtree, ql, qr),
               query(index * 2 + 1, mid + 1, right, segtree, ql, qr));
}

int32_t main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 1) {
        cout << arr[0] << endl;
        return 0;
    }

    if (k > n) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> dp(n + 1, INT_MAX);
    vector<int> segtree((n + 1) * 4, INT_MAX);

    for (int i = 0; i < k; i++) {
        dp[i] = arr[i];
        update(1, 1, n, segtree, i, arr[i]);
    }

    for (int i = k; i <= n; i++) {
        int temp = query(1, 1, n, segtree, i - k, i - 1);

        dp[i] = max(temp, arr[i]);
        if (i == n) continue;
        update(1, 1, n, segtree, i, max(temp, arr[i]));
    }

    if (dp[n] == INT_MAX) {
        for (int i = 0; i < k; i++) {
            dp[i] = arr[i];
        }

        for (int i = k; i <= n; i++) {
            int temp = INT_MAX;
            for (int j = 1; j <= k; j++) {
                temp = min(temp, dp[i - j]);
            }
            dp[i] = max(temp, arr[i]);
        }

        cout << dp[n] << endl;
        return 0;
    }

    cout << dp[n] << endl;
}
