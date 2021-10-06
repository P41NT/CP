#include <bits/stdc++.h>

using namespace std;

#define int long long int


struct cave{
    int b;
    int k;
};

inline bool cmp(cave a, cave b){
    if(a.b == b.b) return a.k > b.k;
    return a.b < b.b;
}

void solve(){
    int a;
    cin>>a;
    vector<cave> caves(a + 1);
    for(int j = 1; j <= a; j++){
        int h;
        cin>>h; 
        caves[j].k = h;
        for(int i = 1; i <= h; i++){
            int temp; cin>>temp;
            caves[j].b = max(caves[j].b, temp - i + 1);
        }
    }
    sort(caves.begin(), caves.end(), cmp);
    int p = 0;
    int ck = 0;
    for(int i = 0; i < caves.size(); i++){
        p = max(p, caves[i].b - ck);
        ck += caves[i].k;
    }
    cout<<p + 1<<endl;
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
