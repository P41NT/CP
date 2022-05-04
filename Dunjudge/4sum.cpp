#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<int> ar(a), br(b), cr(c), dr(d);

    for (int i = 0; i < a; i++) cin >> ar[i];
    for (int i = 0; i < b; i++) cin >> br[i];
    for (int i = 0; i < c; i++) cin >> cr[i];
    for (int i = 0; i < d; i++) cin >> dr[i];

    map<int, bool> mp;
    map<int, pair<int, int>> values;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            mp[ar[i] + br[j]] = true;
            values[ar[i] + br[j]] = {ar[i], br[j]};
        }
    }

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < d; j++) {
            if (mp[-(cr[i] + dr[j])]) {
                auto val = values[-(cr[i] + dr[j])];
                cout << val.first << " " << val.second << " " << cr[i] << " "
                     << dr[j] << endl;
                return 0;
            }
        }
    }
}
