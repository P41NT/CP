#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    deque<int> ans;

    int k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (n % 2 == 0) {
            if (i % 2 == 0)
                ans.push_back(k);
            else
                ans.push_front(k);
        } else {
            if (i % 2 == 0)
                ans.push_front(k);
            else
                ans.push_back(k);
        }
    }

    for (auto s : ans) {
        cout << ans.front() << " ";
        ans.pop_front();
    }
    cout << endl;
}
