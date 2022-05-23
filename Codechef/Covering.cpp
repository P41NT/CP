#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

inline bool compare(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

void solve(){
    //code goes here
    int n; cin>>n;
    vector<pair<int, int> > arr(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin>>a>>b;
        arr[i] = {a, b};
    }
    sort(arr.begin(), arr.end(), compare);
    int ans = 0;
    int x = -1;
    for(auto i : arr){
        if(i.first > x){
            x = i.second; 
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
    t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    //================================================================

    return 0;
}