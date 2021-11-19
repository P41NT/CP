#include <bits/stdc++.h>

using namespace std;

void print_pattern(vector<int> &arr){
    vector<int> temp(arr.size());
    int curr = 8;
    while(curr != 0){
        cout<<curr;
        curr = arr[curr];
    }
}

bool line_between(int a, int b, vector<int> &arr){
    if(arr[a] == b || arr[b] == a) return true;
    return false;
}

bool checker(vector<int> &arr){
    if(!line_between(1, 3, arr)) return false;
    if(!line_between(4, 6, arr)) return false;
    if(!line_between(7, 9, arr)) return false;
    if(!line_between(2, 8, arr)) return false;
    if(!line_between(1, 6, arr)) return false;
    if(!line_between(4, 9, arr)) return false;
    print_pattern(arr);
    cout<<endl;
    return true;
}

void getans(vector<bool> visited, int node, vector<int> ans){
    visited[node] = true;
    if(node == 7) checker(ans);
    for(int i = 1; i < 10; i++){
        if(!visited[i]){
            ans[i] = node;
            getans(visited, i, ans);
        }
    }
}

int main(){
    map<pair<int, int>, int> nodes_between= {
        {make_pair(1, 3), 2},
        {make_pair(3, 1), 2}, 
        {make_pair(1, 7), 4},
        {make_pair(7, 1), 4},
        {make_pair(1, 9), 5},
        {make_pair(9, 1), 5},
        {make_pair(3, 7), 5},
        {make_pair(7, 3), 5},
        {make_pair(3, 9), 6},
        {make_pair(9, 3), 6},
        {make_pair(7, 9), 8},
        {make_pair(9, 7), 8},
        {make_pair(2, 8), 5},
        {make_pair(8, 2), 5},
        {make_pair(4, 6), 5},
        {make_pair(6, 4), 5}
    };   
    vector<bool> visited(10);
    vector<int> ans(10);
    for(int i = 1; i < 10; i++){
        if(i != 7) getans(visited, i, ans);
    }
}