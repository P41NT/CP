#include <iostream>
#include <vector>

using namespace std;

#define int long long int

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));

    int total = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            total += arr[i][j];
            arr[i][j] = (arr[i][j] == 0) ? -1 : 1;
        }
    }

    vector<vector<int>> prefix(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= m; i++) {
        prefix[1][i] = arr[1][i];
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefix[i][j] = prefix[i - 1][j] + arr[i][j];
        }
    }

    int sum = 0;
    for (int up = 1; up <= n; up++) {
        for (int down = up; down <= n; down++) {
            int cum = 0;
            for (int slider = 1; slider <= m; slider++) {
                cum += prefix[down][slider] - prefix[up - 1][slider];
                sum = max(sum, cum);
                cum = max(cum, 0ll);
            }
        }
    }
    cout << total - sum << endl;
}
