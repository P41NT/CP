#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr(300);
vector<vector<int>> dp(300, vector<int>(3));

int sol(int i, int k) {
    if (i >= n) return 0;
    if (i == n - 1) {
        return arr[n - 1];
    }
    cout << i << " " << k << " ";
    if (k == 2) {
        if (i + 2 < n) {
            cout << sol(i + 2, 1) + arr[i + 2] << endl;
            return sol(i + 2, 1) + arr[i + 2];
        } else {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << max(sol(i + 1, k + 1) + arr[i + 1], sol(i + 2, 1) + arr[i + 2])
         << endl;
    return max(sol(i + 1, k + 1) + arr[i + 1], sol(i + 2, 1) + arr[i + 2]);
}

int32_t main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << sol(0, 1) << endl;
}
