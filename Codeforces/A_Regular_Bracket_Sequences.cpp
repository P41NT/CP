#include <bits/stdc++.h>

using namespace std;



int main(){
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        for(int i = 1; i <= n; i++){
            string var = "";
            for(int j = 0; j < i; j++){
                var += "()";
            }
            for(int j = 0; j < n-i; j++){
                var = "(" + var + ")";
            }
            cout<<var<<endl;
        }
    }
}