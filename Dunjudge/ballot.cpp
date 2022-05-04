#include <iostream>
#include <map>
#include <set>

using namespace std;

#define int long long int

int32_t main() {
    int n, m;
    cin >> n >> m;

    map<int, int> indices;
    set<int> st;

    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;

        st.insert(temp);
        indices[temp] = i + 1;
    }

    for (int i = 0; i < m; i++) {
        cin >> temp;
        auto j = st.lower_bound(temp);
        auto k = j;
        k--;

        auto h = ((abs(*k - temp)) < (abs(*j - temp))) ? k : j;
        if (abs(*k - temp) == abs(*j - temp)) {
            h = (indices[*k] < indices[*j]) ? k : j;
        }

        cout << indices[*h] << endl;
        st.erase(h);
    }
}
