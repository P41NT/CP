#include <iostream>

using namespace std;

#define int long long int

int m, d;
bool ok(int k) {
    int sum = k;
    int curr = k;
    int num = 1;
    while ((int)(curr / (d * num)) > 0) {
        // cout << curr << " " << num << " " << sum << endl;
        curr = (int)(curr / (d * num++));
        sum += curr;
        if (sum >= m) return true;
    }

    return false;
}

int32_t main() {
    cin >> m >> d;

    int l = 1, r = m;
    int ans = m;
    while (l <= r) {
        int mid = (l + r) / 2;

        if (ok(mid)) {
            ans = min(ans, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;
}
