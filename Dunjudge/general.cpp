#include <iostream>
#include <vector>

#define int long long int

using namespace std;

struct UFDS {
    vector<int> link, soldiers;
    UFDS(int n, vector<int> &soldiers) {
        link.resize(n + 1);
        this->soldiers = soldiers;
        for (int i = 1; i <= n; i++) {
            link[i] = i;
        }
    }

    int root(int i) {
        if (link[i] == i) return i;
        return link[i] = root(link[i]);
    }

    int unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return -1;
        if (soldiers[y] > soldiers[x]) {
            swap(x, y);
        }

        link[y] = x;

        return x;
    }

    void getAns(int x, int y) { cout << unite(x, y) << endl; }
};

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<int> soldiers(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> soldiers[i];
    }

    UFDS ufds(n, soldiers);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ufds.getAns(a, b);
    }
}
