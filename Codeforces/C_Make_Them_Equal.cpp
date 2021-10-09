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
    //code goes here
    int n;
    char c;
    cin>>n>>c;
    vector<char> s(n + 1);
    bool ok = true;
    for(int i = 1; i <= n; i++){
        cin>>s[i];
        if(s[i] != c) ok = false;
    }
    if(!ok){
        for(int i = 1; i <= n; i++){
            ok = true;
            for(int j = i; j <= n; j += i){
                ok &= s[j] == c;
            }
            if(ok){
                cout<<1<<endl<<i<<endl;
                break;
            }
        }
        if(!ok){
            cout<<2<<endl<<n-1<<" "<<n<<endl;
        }
    }
    else{
        cout<<0<<endl;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //================================================================
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    //================================================================

    return 0;
}