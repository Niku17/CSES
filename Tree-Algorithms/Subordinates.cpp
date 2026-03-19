#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int,int>dp;

int solve(int node, vector<vector<int>>& adj){
    if(adj[node].size() == 0) return 0 ;
    if(dp.find(node) != dp.end()) return dp[node];

    int ans = 0;
    for(auto nei : adj[node]){
        ans += 1 + solve(nei, adj);  
    }

    return dp[node] = ans;
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1); 

    for(int i = 2; i <= n; i++){
        int boss;
        cin >> boss;
        adj[boss].push_back(i); 
    }

    solve(1, adj); 

    for(int i = 1; i <= n; i++){
        cout << dp[i] << " ";
    }

    return 0;
}