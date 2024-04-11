class Solution {
public:

typedef  pair<int, pair<int, int>> P;
vector<vector<int>> dirs = {{-1, 0}, {1,0}, {0,-1}, {0,1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        priority_queue<P, vector<P>, greater<P>> pq;

        auto isSafe = [&](int i, int j) {
            return i >= 0 && i< m && j>=0 && j< n;
        };

        result[0][0] = 0;
        pq.push({0, {0,0}});

        while(!pq.empty()) {
            int diff = pq.top().first;
            auto coord = pq.top().second;
            pq.pop();

            int i = coord.first;
            int j = coord.second;

            if( i == m-1 && j == n-1)
            return diff;

            for(auto &dir : dirs) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if(isSafe(i_, j_)) {
                    int absDiff =abs( heights[i][j] - heights[i_][j_]);
                    int maxDiff = max(diff, absDiff);

                    if(result[i_][j_] > maxDiff) {
                        result[i_][j_] = maxDiff;
                        pq.push({maxDiff, {i_, j_}});
                    }

                }
            }
        }

        return result[m-1][n-1];
        
    }
};
