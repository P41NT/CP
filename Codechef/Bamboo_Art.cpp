#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve(){
    //code goes here
    int n, m = 0;
    cin>>n;
    vector<int> arr(n + 1);
    for(int i =1 ; i <= n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    int max_length = 2;
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            int len = 2;
            int diff = arr[j] - arr[i]; 
            int next = arr[j] + diff;
            for(int k = j + 1; k <= n; k++){
                if(next == arr[k]) {
                    len ++;
                    max_length = max(max_length, len);
                    next = next + diff;
                }
            }
        }
    }
    cout<<max_length<<endl;
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