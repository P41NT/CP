#include <bits/stdc++.h>

using namespace std;

#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> h(n);
    int total = 0;
    for(int i = 0; i < n; i++){
        cin>>h[i];
        total += h[i];
    }
    int m;
    cin>>m;
    int u, v;
    sort(h.begin(), h.end());
    while(m--){
        cin>>u>>v;
        int attacker1 = *lower_bound(h.begin(), h.end(), u);
        int attacker2 = *(--upper_bound(h.begin(), h.end(), u));
        cout<<min(  max(u - attacker1, 0ll) + max(v - total + attacker1, 0ll),
                    max(u - attacker2, 0ll) + max(v - total + attacker2, 0ll))<<"\n";
    }
    return 0;
}