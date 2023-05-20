// DFS Approach //
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;

        for (int i = 0; i < equations.size(); i++) {
            string dividend = equations[i][0];
            string divisor = equations[i][1];
            double value = values[i];

            graph[dividend][divisor] = value;
            graph[divisor][dividend] = 1.0 / value;
        }

        vector<double> results;

        for (auto query : queries) {
            string dividend = query[0];
            string divisor = query[1];

            if (graph.find(dividend) == graph.end() || graph.find(divisor) == graph.end()) {
                results.push_back(-1.0);
            } else {
                unordered_set<string> visited;
                double result = -1.0;
                dfs(dividend, divisor, graph, visited, result, 1.0);
                results.push_back(result);
            }
        }

        return results;
    }

private:
    void dfs(string node, string& dest, unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited, double& result, double temp) {
        if (visited.find(node) != visited.end()) return;

        visited.insert(node);
        if (node == dest) {
            result = temp;
            return;
        }

        for (auto ne : graph[node]) {
            dfs(ne.first, dest, graph, visited, result, temp * ne.second);
        }
    }
};
