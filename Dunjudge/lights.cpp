#include <iostream>

using namespace std;

#define int long long int

int32_t main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i * i <= n; i++) {
        ans++;
    }

    cout << ans << endl;
}
