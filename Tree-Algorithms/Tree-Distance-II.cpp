#include <iostream>
#include <vector>
using namespace std;

long long subtreeCount(int node, vector<long long>& ss, vector<vector<int>> &adj, vector<bool>& visited){
    visited[node] = 1;
    long long ans = 0;
    for(auto nei : adj[node]){
        if(visited[nei]) continue;
        ans += (1 + subtreeCount(nei, ss, adj, visited));
    }
    ss[node] += ans;
    return ans;
}

long long dfs(int node, vector<long long>& dist, vector<long long>& ss,
              vector<vector<int>>& adj, vector<bool>& visited){
    visited[node] = 1;
    for(auto nei : adj[node]){
        if(visited[nei]) continue;
        dist[node] += (dfs(nei, dist, ss, adj, visited) + ss[nei]);
    }
    return dist[node];
}

long long compute(int node, vector<long long>& dist, vector<long long>& ss,
                  vector<long long>& final_dist, vector<vector<int>>& adj, vector<bool>& visited){

    visited[node] = 1;

    for(auto nei : adj[node]){
        if(visited[nei]) continue;

        final_dist[nei] = final_dist[node] - ss[nei] + ((long long)ss.size() - 1 - ss[nei]);

        compute(nei, dist, ss, final_dist, adj, visited);
    }
    return 0;
}

int main(){

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<long long> ss(n + 1, 1);
    vector<long long> dist(n + 1, 0);
    vector<bool> visited(n + 1, 0);

    long long k = subtreeCount(1, ss, adj, visited);

    fill(visited.begin(), visited.end(), 0);
    k = dfs(1, dist, ss, adj, visited);

    vector<long long> final_dist(n + 1, 0);
    final_dist[1] = dist[1];

    fill(visited.begin(), visited.end(), 0);
    compute(1, dist, ss, final_dist, adj, visited);

    for(int i = 1; i <= n; i++){
        cout << final_dist[i] << " ";
    }
}