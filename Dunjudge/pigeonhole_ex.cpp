#include <bits/stdc++.h>

using namespace std;

#define int long long int

void increment(vector<int> &segtree, int index, int start, int end, int position){
    if(start == end && start == position) {
        segtree[index]++;
        return;
    }
    int mid = (start + end) / 2;

    if(position<= mid)
        increment(segtree, index * 2, start, mid, position);
    else
        increment(segtree, index * 2 + 1, mid  + 1, end , position);

    segtree[index] = max(segtree[index * 2], segtree[index * 2 + 1]);
}
void decrement(vector<int> &segtree, int index, int start, int end, int position){
    if(start == end && start == position) {
        segtree[index]--;
        return;
    }
    int mid = (start + end) / 2;

    if(position<= mid)
        decrement(segtree, index * 2, start, mid, position);
    else
        decrement(segtree, index * 2 + 1, mid + 1, end , position);

    segtree[index] = max(segtree[index * 2], segtree[index * 2 + 1]);
}

int32_t main() {
    int n, h;
    cin >> n >> h;

    vector<int> mp(n);
    vector<int> segtree((n + 1) * 4);

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;

        int x = (b % h);
        if (a== 0) {
            mp[x]--;
            decrement(segtree, 1, 0, n - 1, x);
        }
        else {
            mp[x]++;
            increment(segtree, 1, 0, n - 1, x);
        }
        cout << segtree[1] << endl;
    }
}