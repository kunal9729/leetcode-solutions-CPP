class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    int m = matrix.size(), n = matrix[0].size();
    int i, k = 0, l = 0;

    while (k < m && l < n) {
        // Traverse the top row
        for (i = l; i < n; ++i) result.push_back(matrix[k][i]);
        k++;

        // Traverse the right column
        for (i = k; i < m; ++i) result.push_back(matrix[i][n-1]);
        n--;

        // Traverse the bottom row
        if (k < m) {
            for (i = n-1; i >= l; --i) result.push_back(matrix[m-1][i]);
            m--;
        }

        // Traverse the left column
        if (l < n) {
            for (i = m-1; i >= k; --i) result.push_back(matrix[i][l]);
            l++;
        }
    }

    return result;
}

  
    
};

// t.c O(mn)
// s.c O(mn)