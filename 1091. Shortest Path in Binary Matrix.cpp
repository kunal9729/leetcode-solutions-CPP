//************************************************************************//
//************************************************************************//
class Solution 
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0},
                                          {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int lengthOfPath = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if (x == n - 1 && y == n - 1)
                    return lengthOfPath;

                for (const auto& direction : directions) {
                    int newx = x + direction[0];
                    int newy = y + direction[1];

                    if (newx >= 0 && newy >= 0 && newx < n && newy < n && grid[newx][newy] == 0) {
                        q.push({newx, newy});
                        grid[newx][newy] = 1;
                    }
                }
            }
            lengthOfPath++;
        }

        return -1;
    }
};
