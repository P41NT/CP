#include <iostream>
#include <vector>

using namespace std;

int32_t main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> dp(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0] = 0;
    dp[1] = abs(arr[0] - arr[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1] + abs(arr[i] - arr[i - 1]),
                    dp[i - 2] + abs(arr[i] - arr[i - 2]));
    }

    cout << dp[n - 1] << endl;
}
