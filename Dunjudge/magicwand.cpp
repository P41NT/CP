#include <iostream>
#include <vector>

using namespace std;

const int maxh = 500;
const int maxw = 500;

const int dir_x[4] = {0, 1, 0, -1};
const int dir_y[4] = {1, 0, -1, 0};

int h, w;

vector<vector<int>> arr(maxh, vector<int>(maxw));
vector<vector<bool>> ans(maxh, vector<bool>(maxw));
vector<vector<bool>> visited(maxh, vector<bool>(maxw));

void bfs(int x, int y, int t, int o) {
    if (x < 0 || x >= h) return;
    if (y < 0 || y >= w) return;
    if (visited[x][y]) return;

    if (!(abs(arr[x][y] - o) <= t)) return;

    ans[x][y] = true;
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        bfs(x + dir_x[i], y + dir_y[i], t, o);
    }
}

int main() {
    int x, y, t;
    cin >> h >> w >> x >> y >> t;
    x--, y--;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> arr[i][j];
        }
    }

    bfs(x, y, t, arr[x][y]);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
}
