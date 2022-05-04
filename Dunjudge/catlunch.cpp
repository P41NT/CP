#include <bits/stdc++.h>

using namespace std;

#define int long long int

int32_t main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int i = 0;
    for (; i < k; i++) {
        pq.push(arr[i]);
    }

    int curr = 0, ans = 0;

    while (!pq.empty()) {
        curr += pq.top();
        pq.pop();
        ans = max(ans, curr);
        if (i < n) pq.push(arr[i++]);
    }

    cout << ans << endl;
}
