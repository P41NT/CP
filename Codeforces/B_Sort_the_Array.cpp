
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve(){
    //code goes here
    int n;
    cin>>n;
    vector<int> arr(n + 1);
    vector<int> copy(n + 1);
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        copy[i] = arr[i];
    }
    sort(copy.begin(), copy.end());
    int l = -1, r = -1; 
    for(int i = 1; i <= n; i++){
        if(arr[i] != copy[i]){
            r = i;
            if(l == -1){
                l = i;
            }
        }
    }
    if(l == -1) l = 1, r = 1;
    reverse(arr.begin() + l, arr.begin() + r + 1);
    bool notpossible = false;;
    for(int i = 1; i<= n; i++){
        if(arr[i] != copy[i]){
            notpossible = true;
            break;
        }
    }
    if(notpossible){
        cout<<"no"<<endl;
    }
    else{
        cout<<"yes"<<endl<<l<<" "<<r<<endl;
    }
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