#include <iostream>
#include <vector>

using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int k = 5; k <= n; k++) {
        for (int i = k; i <= n; i++) {
            dp[i] += dp[i - k];
        }
    }

    cout << dp[n] << endl;
}
