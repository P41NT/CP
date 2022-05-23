#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve(){
    //code goes here
    int n;
    cin>>n;
    vector<vector<int>> data(n, vector<int>(5));
    for(int i = 0; i < n; i++){
        for(int j= 0;j < 5;j ++){
            cin>>data[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                int curr = INT_MAX;
                // cout<<"SOMETHING"<<" ";
                for(int m = 0; m < 5; m++){
                    curr = min(curr, max({data[i][m], data[j][m], data[k][m]}));
                    // cout<<curr<<" ";
                }
                ans = max(ans, curr);
            }
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