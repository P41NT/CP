#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve(){
    int n, l;
    cin>>n>>l;
    vector<int> v(n);
    for(int i = 0;i < n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    int h;
    for(int i = n; i>= 1; i--){
        if(v[i - 1] >= i){
            h = i;
            break;
        }
    }
    for(int i = h + 1; i <= min(n, h + l); i++){
        v[i-1]++;
    }
    for(int i = n; i>= 1; i--){
        if(v[i - 1] >= i){
            h = i;
            break;
        }
    }
    cout<<h<<endl;
}

int32_t main(){
    int t;
    t = 1;
    while(t--){
        solve();
    }
}
