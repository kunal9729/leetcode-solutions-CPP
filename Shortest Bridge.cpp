class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        vector<pair<int, int>> first, second;
        
        function<void(int, int, int)> mark = [&](int i, int j, int no) {
            if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1) return;
            grid[i][j] = no;
            (no == 2 ? first : second).emplace_back(i, j);
            mark(i+1, j, no);
            mark(i-1, j, no);
            mark(i, j+1, no);
            mark(i, j-1, no);
        };
        
        int count = 2;
        for (auto i = 0; i < grid.size(); ++i) {
            for (auto j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) mark(i, j, count++);
            }
        }
        
        int ans = INT_MAX;
        for (const auto& f : first) {
            for (const auto& s : second) {
                ans = min(ans, abs(f.first - s.first) + abs(f.second - s.second) - 1);
            }
        }
        
        return ans;
    }
};
