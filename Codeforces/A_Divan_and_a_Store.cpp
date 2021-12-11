#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve(){
    //code goes here
    int n, l, r, k;
    cin>>n>>l>>r>>k;
    vector<int> arr;
    for(int i = 1; i <= n; i++){
        int temp; cin>>temp;
        if(temp >= l && temp <= r) arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    int curr = 0; int ans = 0;
    for(auto s : arr) {
        // cout<<s<<" ";
        if(curr > k) break;
        else if(curr + s <= k){
            curr += s;
            ans++;
        } 
    }
    cout<<ans<<endl;
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