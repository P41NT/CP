#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve(){
    int k, n;
    cin>>k>>n;
    map<string,int> names;
    for(int i = 0; i < n; i++){
        string temp;
        cin>>temp;
        names.insert(make_pair(temp, i));
    }
    vector< vector<char> > ans(n, vector<char>(n));
    for(int i = 0; i< n; i++){
        for(int j = 0; j < n; j++){
            if(j == i) ans[i][j] = 'B';
            else ans[i][j] = '?';
        }
    }
    for(int u = 0; u < k; u++){
        vector<string> row(n);
        for(int j = 0; j< n; j++){
            cin>>row[j];
        }
        for(int i = 0; i< n-1; i++){
            for(int j = i + 1; j < n; j++){
                if(row[j] < row[i]){
                    ans[names[row[j]]][names[row[i]]] = '1';
                    ans[names[row[i]]][names[row[j]]] = '0';
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}

int32_t main(){
    int t;
    t = 1;
    while(t--){
        solve();
    }
}
