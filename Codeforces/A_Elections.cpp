#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define vector2d(x, y, r) vector<vector<int>>(x, vector<int>(y, r));
#define vector3d(x, y, z, r) vector<vector<vector<int>>>(x, vector<vector<int>>(y, vector<int>(z, r)))
#define forj(i, j) for(int i = 0; i < j; i++) 
#define ford(i, j) for(int i = j; i >= 0; i--)
#define loop(i, l, j, h) for(int i = l; i <= j; h)

void solve(){
    vector<int> arr(3);
    int required = 0;
    int max_count = 0;
    for(int i = 0; i < 3; i++){
        cin>>arr[i];
        if(arr[i] == required){
            max_count ++;
        }
        else if(arr[i] > required){
            required = arr[i];
            max_count = 1;
        } 
    }
    for(int i = 0; i < 3; i++){
        if(arr[i] == required && max_count > 1){
            cout<<1<<" ";
        }
        else if(arr[i] == required){
            cout<<0<<" ";
        }
        else{
            cout<<required-arr[i] + 1<<" ";
        }
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