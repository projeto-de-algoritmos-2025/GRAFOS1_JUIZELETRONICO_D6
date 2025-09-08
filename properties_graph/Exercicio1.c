#include <vector>
#include <unordered_set>

class Solution {
private:
    void dfs(int u, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v, adj, visited);
            }
        }
    }

public:
    int numberOfComponents(std::vector<std::vector<int>>& properties, int k) {
        int n = properties.size();
        if (n <= 1) {
            return n;
        }

        std::vector<std::unordered_set<int>> sets(n);
        for (int i = 0; i < n; ++i) {
            sets[i] = std::unordered_set<int>(properties[i].begin(), properties[i].end());
        }

        std::vector<std::vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                
                int common_count = 0;

                if (sets[i].size() < sets[j].size()) {
                    for (int val : sets[i]) {
                        if (sets[j].count(val)) {
                            common_count++;
                        }
                    }
                } else {
                    for (int val : sets[j]) {
                        if (sets[i].count(val)) {
                            common_count++;
                        }
                    }
                }
                
                if (common_count >= k) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        std::vector<bool> visited(n, false);
        int component_count = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                component_count++;
                dfs(i, adj, visited);
            }
        }

        return component_count;
    }
};