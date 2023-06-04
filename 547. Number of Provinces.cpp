class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        int n = isConnected.size();
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                provinces++;
                dfs(isConnected, visited, i);
            }
        }

        return provinces;
    }

    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int node) {
        visited[node] = true;
        for (int neighbor = 0; neighbor < isConnected.size(); neighbor++) {
            if (isConnected[node][neighbor] && !visited[neighbor]) {
                dfs(isConnected, visited, neighbor);
            }
        }
    }
};
