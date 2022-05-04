#include <cstdint>
#include <iostream>
#include <vector>

#define int long long
#define endl "\n"

using namespace std;

int32_t main() {
    int r, c;
    cin >> r >> c;

    vector<vector<int>> dp(26, vector<int>(26));

    for (int i = 1; i <= 25; i++) {
        dp[i][1] = 1;

        for (int j = 2; j <= i; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }

    cout << dp[r][c] << endl;
}
