#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    map<int, int> ans;
    int currentprime = 2;
    while (n > 1) {
        if (n % currentprime == 0) {
            ans[currentprime]++;
            n /= currentprime;
        } else
            currentprime++;
    }

    for (auto s : ans) {
        cout << s.first << "^" << s.second << endl;
    }
}
