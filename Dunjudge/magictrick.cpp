#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        vector<bool> taken(17);
        int first;
        cin >> first;
        vector<vector<int>> arr(5, vector<int>(5));
        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) {
                cin >> arr[i][j];
                if (i == first) {
                    taken[arr[i][j]] = true;
                }
            }
        }

        int second;
        cin >> second;
        int ans = 0, counter = 0;
        vector<vector<int>> arr2(5, vector<int>(5));
        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) {
                cin >> arr2[i][j];
                if (i == second)
                    if (taken[arr2[i][j]]) {
                        counter++;
                        ans = arr2[i][j];
                    }
            }
        }

        cout << "Case #" << i << ": ";
        if (counter == 0)
            cout << "Volunteer cheated!" << endl;
        else if (counter > 1)
            cout << "Bad magician!" << endl;
        else
            cout << ans << endl;
    }
}
