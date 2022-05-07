#include <climits>
#include <iostream>
#include <set>

using namespace std;

int32_t main() {
    int n, m;
    cin >> n >> m;

    set<pair<int, int>> st = {{INT_MIN, INT_MIN}, {INT_MAX, INT_MAX}};

    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;

        st.insert({temp, i + 1});
    }

    for (int i = 0; i < m; i++) {
        cin >> temp;
        auto upper_pos = st.lower_bound({temp, INT_MIN});
        auto lower_pos = --upper_pos;
        ++upper_pos;

        if (abs(temp - (*lower_pos).first) <= abs(temp - (*upper_pos).first)) {
            cout << (*lower_pos).second << endl;
            st.erase(lower_pos);
        } else {
            cout << (*upper_pos).second << endl;
            st.erase(upper_pos);
        }
    }
}