#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> total;
    while (n--) {
        set<int> st;
        int k;
        cin >> k;
        int temp;
        while (k--) {
            cin >> temp;
            st.insert(temp);
            total.insert(temp);
        }

        cout << st.size() << endl;
    }
    cout << total.size() << endl;
}
