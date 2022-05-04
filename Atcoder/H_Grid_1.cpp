#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

#define int long long int
#define endl "\n"

int32_t main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> arr(h + 1, vector<char>(w + 1));

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dp(h + 1, vector<int>(w + 1));

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (arr[i][j] == '#')
                continue;
            if (i == 1 && j == 1)
                dp[i][j] = 1;
            else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
            dp[i][j] %= mod;
        }
    }

    cout << dp[h][w] << endl;
}
