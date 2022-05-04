#include <bits/stdc++.h>

using namespace std;

const int dir_x[4] = {0, 1, 0, -1};
const int dir_y[4] = {1, 0, -1, 0};

const int maxr = 40, maxc = 40;

vector<vector<int>> arr(maxr + 1, vector<int>(maxc + 1));
vector<vector<int>> visited(maxr + 1, vector<int>(maxc + 1));

int r, c;

int dfs(int row, int col) {
    if (row == r - 1 && col == c - 1) return arr[r - 1][c - 1];
    pair<int, pair<int, int>> maxneighbour = {-1, {-1, -1}};

    visited[row][col] = true;

    for (int i = 0; i < 4; i++) {
        if (row + dir_x[i] >= r || row + dir_x[i] < 0) continue;
        if (col + dir_y[i] >= c || col + dir_y[i] < 0) continue;
        if (visited[row + dir_x[i]][col + dir_y[i]]) continue;

        maxneighbour = max(maxneighbour, {arr[row + dir_x[i]][col + dir_y[i]],
                                          {row + dir_x[i], col + dir_y[i]}});
    }

    return arr[row][col] +
           dfs(maxneighbour.second.first, maxneighbour.second.second);
}

int main() {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    cout << dfs(0, 0) << endl;
}
