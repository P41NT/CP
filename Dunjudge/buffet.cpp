#include <iostream>
#include <vector>

using namespace std;

#define int long
#define endl "\n"

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int arr[n][2];

    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            cin >> arr[i][j];
        }
    }

    int a, b, c, d;

    a = arr[0][0];
    b = arr[0][1];

    for (int i = 1; i < n; i++) {
        c = arr[i][0], d = arr[i][1];
        c += max(a, b - k), d += max(b, a - k);
        a = c;
        b = d;
    }
    cout << max(a, b) << endl;
}
