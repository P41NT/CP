#include <bits/stdc++.h>

using namespace std;

#define int long long int

vector<int> dp(30000000, -1);

int sol(int n) {
    if (n < 0) return INT_MAX;
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];
    int ans = INT_MAX;
    if (n % 2 == 0) ans = min(ans, 1 + sol(n / 2));
    if (n % 3 == 0) ans = min(ans, 1 + sol(n / 3));
    ans = min(ans, 1 + sol(n - 1));

    return dp[n] = ans;
}

int32_t main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        cout << sol(arr[i]) << endl;
    }
}
