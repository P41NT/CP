#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<string> st;

    for (int i = 1; i <= n; i++) {
        string thisline = "";
        for (int j = 1; j <= n; j++) {
            thisline += min(i, j) + '0';
        }

        string full = thisline;

        reverse(thisline.begin(), thisline.end());
        full += thisline;
        cout << full << endl;
        st.push(full);
    }

    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
}
