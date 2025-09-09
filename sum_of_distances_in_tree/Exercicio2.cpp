vector <int> sumOfDistancesInTree (int n, vector<vector<int>>& edges){
	vector <vector <int>> adj(n);

	for ( const auto& edge : edges){
		int u = edge[0];
		int v = edge[1];
			
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector <int> result(n);

	for (int i = 0; i < n; ++i){
		queue<int> q;
		vector<int> dist(n, -1);

		q.push(i);
		dist[i] = 0;

		while (!q.empty()){
			int noAtual = q.front();
			q.pop();

			for(int vizinho : adj[noAtual])
				if (dist[vizinho] == -1){
					dist[vizinho] = dist[noAtual] + 1;
					q.push(vizinho);
				}
		}

		int soma = 0;
		for(int d : dist)
			soma += d;

		result[i] = soma;
	}
	
	return result;
}
