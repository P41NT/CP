#include <iostream>
#include <vector>

using namespace std;

#define int long long int

int32_t main() {
    int n, w;
    cin >> n >> w;

    vector<int> weights(n + 1);
    vector<int> values(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> weights[i] >> values[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(w + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - weights[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i]] + values[i]);
            }
        }
    }

    cout << dp[n][w] << endl;
}
