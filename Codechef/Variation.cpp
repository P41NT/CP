#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define forj(i, k, j) for(int i = k; i <= j; i++)

void solve(){
    //code goes here
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i = 0; i< n; i++)
        cin>>arr[i];
    sort(arr.begin(), arr.end());
    int ans = 0;
    int i, j; i = j = 0;
    while(i < n){
        if(j < i) j = i + 1;
        if(j >= n) break;
        if(abs(arr[i] - arr[j]) >= k){
            i++;
            ans += n - j;
        }
        else{
            j++;
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