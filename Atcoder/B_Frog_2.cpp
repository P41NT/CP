#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int l = 1; l <= k; l++) {
            if (i - l >= 0) {
                dp[i] = min(dp[i], dp[i - l] + abs(arr[i - l] - arr[i]));
            }
        }
    }

    cout << dp[n - 1] << endl;
}
