#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

void dfs(int node, int parent, int depth, vector<vector<int>>& adj, vector<int>& dist, int& farthestNode, int& maxDist) {
    dist[node] = depth;
    if (depth > maxDist) {
        maxDist = depth;
        farthestNode = node;
    }
    for (auto nei : adj[node]) {
        if (nei != parent) dfs(nei, node, depth + 1, adj, dist, farthestNode, maxDist);
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dist(n + 1, 0);
    int u = 1, maxDist = 0;
    dfs(1, 0, 0, adj, dist, u, maxDist);

    dist.assign(n + 1, 0);
    int v = u;
    maxDist = 0;
    dfs(u, 0, 0, adj, dist, v, maxDist);

    vector<int> distU(n + 1, 0), distV(n + 1, 0);
    int temp = 0;
    dfs(u, 0, 0, adj, distU, temp, temp);
    dfs(v, 0, 0, adj, distV, temp, temp);

    for (int i = 1; i <= n; i++) cout << max(distU[i], distV[i]) << " ";
    cout << endl;
}