class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size(), value = 0;
        vector<int> dp(3, 0);
        for (int i = n - 1; i >= 0; i--)
            dp[i % 3] = max(stoneValue[i] - dp[(i + 1) % 3],
                            max(i + 1 < n ? stoneValue[i] + stoneValue[i + 1] - dp[(i + 2) % 3] : INT_MIN,
                                i + 2 < n ? stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[(i + 3) % 3] : INT_MIN));
        return (value = dp[0]) > 0 ? "Alice" : (value < 0 ? "Bob" : "Tie");
    }
};
