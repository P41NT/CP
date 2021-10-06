#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve(){
    int n;
    cin>>n;
    vector< vector<int> > v(2, vector<int>(n));
    int sums1 = 0, sums2 = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            cin>>v[i][j];
            if(!i) sums1 += v[i][j];
        }
    }
    //cout<<sums1<<" "<<sums2<<endl;
    int ans = INT_MAX;
    for(int i = 0;i < n; i++){
        sums1 -= v[0][i];
        //cout<<i<<") "<<sums1<<" "<<sums2<<endl;
        ans = min(ans, max(sums1, sums2));
        sums2 += v[1][i];
    }
    cout<<ans<<endl;
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
