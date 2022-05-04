#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, e1, e2, x1, x2;
    cin >> n >> e1 >> e2;

    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector<int> t1(n + 1);
    vector<int> t2(n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i < n; i++) cin >> t1[i];
    for (int i = 1; i < n; i++) cin >> t2[i];

    cin >> x1 >> x2;

    vector<vector<int>> dp(n + 1, vector<int>(2));
    dp[1][0] = e1 + a[1];
    dp[1][1] = e2 + b[1];

    for (int i = 2; i <= n; i++) {
        dp[i][0] = a[i] + min(dp[i - 1][0], dp[i - 1][1] + t2[i - 1]);
        dp[i][1] = b[i] + min(dp[i - 1][1], dp[i - 1][0] + t1[i - 1]);
    }
    cout << min(dp[n][0] + x1, dp[n][1] + x2) << endl;
}
