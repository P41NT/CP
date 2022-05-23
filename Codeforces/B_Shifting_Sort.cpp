#include <bits/stdc++.h>

using namespace std;

#define int long long int


void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    vector<pair<int, int > > ans;
    for(int i = 0; i < n; i++) {
        int max_ = max_element(v.begin(), v.end()) - v.begin();
        if(max_ != n-i-1){
            ans.push_back(make_pair(max_ + 1, n-i));
        }
        v.erase(v.begin() + max_);
    }
    cout<<ans.size()<<"\n";
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i].first<<" "<<ans[i].second<<" "<<1<<"\n";
    }
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
