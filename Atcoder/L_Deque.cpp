#include <iostream>
#include <vector>

using namespace std;

#define int long long int
#define endl "\n"

int32_t main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < i) continue;
            if (i == j)
                dp[i][j] = arr[i];
            else {
                dp[i][j] = max(dp)
            }
        }
    }
}
