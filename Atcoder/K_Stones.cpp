#include <iostream>
#include <vector>

using namespace std;

#define int long long int
#define end "\n"

int32_t main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<bool> dp(k + 1);
    dp[0] = false;

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (i - arr[j] >= 0)
                dp[i] = dp[i] | !dp[i - arr[j]];
        }
    }

    cout << (dp[k] ? "First" : "Second") << endl;
}
