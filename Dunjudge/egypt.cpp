#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(2 * n, vector<int>(2 * n));

    for (int i = 1; i <= 2 * n - 1; i++) {
        for (int j = 1; j <= 2 * n - 1; j++) {
            arr[i][j] = min({i, j, 2 * n - i, 2 * n - j});
        }
    }

    for (int i = 1; i <= 2 * n - 1; i++) {
        for (int j = 1; j <= 2 * n - 1; j++) {
            cout << arr[i][j];
            if (j != 2 * n - 1) cout << " ";
        }
        if (i != 2 * n - 1) cout << endl;
    }
}
