#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

int n, m, k;

bool check(int a, int b){
    int count = 0;
    int diff = a ^ b;
    for(int i = 0; i < n; i++){
        if(diff & 1) count++;
        diff >>= 1;
    }
    return count <= k;
}

void solve(){
    //code goes here
    cin>>n>>m>>k;
    vector<int> arr(m);
    for(int i = 0; i < m; i++) cin>>arr[i];
    int b; cin>>b;
    int c = 0;
    for(auto a : arr){
        if(check(a, b)) c++;
    }
    cout<<c<<endl;
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