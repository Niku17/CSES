#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

int solve(int node, vector<vector<int>>& adj, unordered_map<int,bool>& visited, int &maxi) {
    visited[node] = true;
    int maxi1 = 0, maxi2 = 0;

    for(auto nei : adj[node]) {
        if(visited[nei]) continue;
        int dist = solve(nei, adj, visited, maxi);
        if(dist > maxi1) {
            maxi2 = maxi1;
            maxi1 = dist;
        } else if(dist > maxi2) {
            maxi2 = dist;
        }
    }

    maxi = max(maxi, maxi1 + maxi2);
    return 1 + maxi1;
}

int main() {
    int n; 
    cin >> n;
    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    unordered_map<int,bool> visited;
    int maxi = INT_MIN;
    solve(1, adj, visited, maxi);

    cout << maxi << endl;
}