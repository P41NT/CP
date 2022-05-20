#include <bits/stdc++.h>

using namespace std;

#define int long long int

vector<int> arr;
int n, m, a, c, x0;

bool binary_search(int value) {
    int start = 0;
    int end = n - 1;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (arr[mid] == value) return true;
        if (arr[mid] > value) end = mid - 1;
        if (arr[mid] < value) start = mid + 1;
    }

    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);

    //#ifndef ONLINE_JUDGE
    //    freopen("../Current/input.txt", "r", stdin);
    //    freopen("../Current/output.txt", "w", stdout);
    //#endif

    cin >> n >> m >> a >> c >> x0;

    arr.resize(n);
    arr[0] = (x0 * a + c) % m;

    for (int i = 1; i < n; i++) {
        arr[i] = (arr[i - 1] * a + c) % m;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (binary_search(arr[i])) ans++;
    }
    cout << ans << endl;
}
