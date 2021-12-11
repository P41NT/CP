#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve(){
    //code goes here
    int n;
    cin>>n;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }
    deque<int> ans;
    if(arr[1] != n && arr[n] != n) cout<<-1<<endl;
    else{
        reverse(arr.begin(), arr.end());
        for(int i = 0; i < n; i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
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