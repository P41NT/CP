#include <limits.h>

#include <iostream>
#include <vector>

#define int long long int
#define endl "\n"

using namespace std;

int32_t main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (k > n) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> dp(n + 1, INT_MAX);

    for (int i = 0; i < k; i++) {
        dp[i] = arr[i];
    }

    for (int i = k; i <= n; i++) {
        int temp = arr[i];
        for (int j = 1; j <= k; j++) {
            dp[i] = min(dp[i], max(dp[i - j], arr[i]));
        }
    }

    cout << dp[n] << endl;
}
