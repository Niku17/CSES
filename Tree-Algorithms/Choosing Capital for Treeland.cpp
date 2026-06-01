#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int dfs2(int node , vector<int>&dp , vector<int>&ss , vector<vector<int>>&adj , vector<bool>&visited){
visited[node] = 1 ;
for( auto nei : adj[node]){
    if(visited[nei]) continue ;
    dp[nei] = dp[node] - ss[nei] + ss[node] - ss[nei];
}
return dp[node];
}

int dfs1( int node , vector<int>&dist , vector<int>&ss , vector<vector<int>>&adj , vector<bool>&visited){
    visited[node] = 1 ;
    for( auto nei : adj[node]){
        if( visited[nei]) continue ;
        dist[node]+= ss[nei] + dfs1( nei , dist , ss , adj , visited ) ;
    }
    return dist[node]; 
}

int subtreeSize( int node , vector<vector<int>>&adj , vector<int>&ss , vector<bool>&visited){
    visited[node] = 1 ;
    int ans = 0 ; 
    for( auto nei : adj[node]){
        if( visited[nei] ) continue ;
        ans +=  (1 + subtreeSize( nei , adj , ss, visited)); 
    }
    ss[node] += ans ;
    return ans ; 
}

int main(){
   int n ;
   cin >> n ;
   vector<vector<int>>adj( n + 1 ) ;
   for( int i = 1 ; i < n ; i++ ){
    int u , v ;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
   }

   vector<int>ss(n+1,1);
   vector<bool>visited(n+1, 0);
   int k = subtreeSize( 1 , adj , ss , visited);

   vector<int>dist(n+1,0);
   for( int i = 0 ; i <= n ; i++){
    visited[i] = 0 ;
   }
   k = dfs1( 1 , dist , ss , adj , visited ) ;
   vector<int>dp( n+1);
   dp[1] = dist[1] + n ; // first step cost 
   for( int i = 0 ; i <= n ; i++){
    visited[i] = 0 ;
   }
   k = dfs2( 1 , dp , ss , adj , visited);
   int ans = 0 ;
   for( int i = 1 ; i <= n ; i++ ){
    ans = max( ans , dp[i]);
   }
   cout<< ans ;
}