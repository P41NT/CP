#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
    
inline bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

void solve(){
    int n;
    cin>>n;
    vector<pair<int, int>> arr(n + 1);
    vector<int> ans(n + 1);
    for(int i = 1; i <= n; i++){
        int temp; cin>>temp;
        arr[i] = {temp, i};
    }
    sort(arr.begin() + 1, arr.end(), cmp);
    ans[0] = 0;
    int sign = 1; int mag = 1;
    int a = 0;
    for(int i = 1; i <= n; i++){
        ans[arr[i].second] = sign * mag;
        a += abs(sign * mag * arr[i].first);
        if(sign == 1) sign *= -1;
        else mag += 1, sign *= -1;
    }
    cout<<a * 2<<endl;
    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //================================================================
    int t;
    // t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    //================================================================

    return 0;
}