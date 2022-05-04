#include <iostream>
#include <vector>

using namespace std;

#define int long long int

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int start = 0, end = 0;
    int sum = 0;

    int ans = 0;

    for (end = 0; end < n; end++) {
        sum += arr[end];
        while (sum > m) {
            sum -= arr[start++];
            if (sum == 0) break;
        }
        ans = max(ans, end - start + 1);
    }

    cout << ans << endl;
}
