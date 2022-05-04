#include <iostream>

using namespace std;

int main() {
    string st;
    cin >> st;
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= (n - i); j++) {
            cout << " ";
        }
        for (int j = 1; j <= i; j++) {
            cout << st[count % st.length()] << " ";
            count++;
        }
        cout << endl;
    }
}
