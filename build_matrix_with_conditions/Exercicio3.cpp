vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
 	vector<vector<int>> adj_lin(k + 1);
        vector<int> vetor_viz_lin(k + 1, 0);

        for (const auto& cond : rowConditions) {
            int u = cond[0];
            int v = cond[1];
            adj_lin[u].push_back(v);
            vetor_viz_lin[v]++;
        }

        queue<int> fila_lin;
        for (int i = 1; i <= k; ++i) {
            if (vetor_viz_lin[i] == 0) {
                fila_lin.push(i);
            }
        }

        vector<int> ordemLin;
        while (!fila_lin.empty()) {
            int u = fila_lin.front();
            fila_lin.pop();
            ordemLin.push_back(u);

            for (int v : adj_lin[u]) {
                vetor_viz_lin[v]--;
                if (vetor_viz_lin[v] == 0) {
                    fila_lin.push(v);
                }
            }
        }

        if (ordemLin.size() != k) {
            return {};
        }

        vector<vector<int>> adj_col(k + 1);
        vector<int> vetor_viz_col(k + 1, 0);

        for (const auto& cond : colConditions) {
            int u = cond[0];
            int v = cond[1];
            adj_col[u].push_back(v);
            vetor_viz_col[v]++;
        }

        queue<int> fila_col;
        for (int i = 1; i <= k; ++i) {
            if (vetor_viz_col[i] == 0) {
                fila_col.push(i);
            }
        }

        vector<int> ordemCol;
        while (!fila_col.empty()) {
            int u = fila_col.front();
            fila_col.pop();
            ordemCol.push_back(u);

            for (int v : adj_col[u]) {
                vetor_viz_col[v]--;
                if (vetor_viz_col[v] == 0) {
                    fila_col.push(v);
                }
            }
        }

        if (ordemCol.size() != k) {
            return {};
        }

        vector<int> posLin(k + 1, 0);
        vector<int> posCol(k + 1, 0);
        for (int i = 0; i < k; ++i) {
            posLin[ordemLin[i]] = i;
            posCol[ordemCol[i]] = i;
        }

        vector<vector<int>> matriz(k, vector<int>(k, 0));
        for (int i = 1; i <= k; ++i) {
            matriz[posLin[i]][posCol[i]] = i;
        }

        return matriz;
}

