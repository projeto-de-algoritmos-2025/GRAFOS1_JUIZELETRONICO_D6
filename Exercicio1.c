#include <vector>
#include <unordered_set>

class Solution {
private:

    int intersect(const std::vector<int>& a, const std::vector<int>& b) {
        std::unordered_set<int> set_a(a.begin(), a.end());
        
        std::unordered_set<int> common_elements;
        for (int val : b) {
            if (set_a.count(val)) {
                common_elements.insert(val);
            }
        }
        return common_elements.size();
    }


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

        std::vector<std::vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (intersect(properties[i], properties[j]) >= k) {
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
