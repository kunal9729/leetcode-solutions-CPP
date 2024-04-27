class Solution {
public:


    bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    dp[0][0] = true; // empty pattern matches empty string
    
    // pre-process patterns with * to match zero element
    for (int j = 1; j <= m; j++) {
        if (p[j-1] == '*') dp[0][j] = dp[0][j-2];
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i-1] == p[j-1] || p[j-1] == '.') {
                dp[i][j] = dp[i-1][j-1];
            } else if (p[j-1] == '*') {
                dp[i][j] = dp[i][j-2]; // match zero preceding element
                if (s[i-1] == p[j-2] || p[j-2] == '.') {
                    dp[i][j] = dp[i][j] || dp[i-1][j]; // match one or more preceding element
                }
            } else {
                dp[i][j] = false; // mismatch
            }
        }
    }
    
    return dp[n][m];
}

};