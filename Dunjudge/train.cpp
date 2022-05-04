#include <limits.h>
#include <iostream>
#include <vector>

using namespace std;

#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n + 2);

    arr[0] = (int)1e9;
    arr[n + 1] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<int> dp(n + 2, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] >= arr[i]) {
                dp[i] = min(dp[i], (i - j) * (i - j) + dp[j]);
            }
        }
    }

    cout << dp[n + 1] << endl;
}
