void dfs1(int u, int parent, vector<vector<int>>& adj, vector<int>& count, vector<int>& ans) {
for (int v : adj[u]) {
    if (v == parent) continue;
    dfs1(v, u, adj, count, ans);
    count[u] += count[v];
    ans[u] += ans[v] + count[v];
    }
}

void dfs2(int u, int parent, int n, vector<vector<int>>& adj, vector<int>& count, vector<int>& ans) {
    for (int v : adj[u]) {
        if (v == parent) continue;
        ans[v] = ans[u] - count[v] + (n - count[v]);
        dfs2(v, u, n, adj, count, ans);
    }
}

vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    if (n == 1)
        return {0};

    vector<vector<int>> adj(n);
    vector<int> count(n, 1);
    vector<int> ans(n, 0);
    
	for (const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    
	dfs1(0, -1, adj, count, ans);
    dfs2(0, -1, n, adj, count, ans);
    
	return ans;
}