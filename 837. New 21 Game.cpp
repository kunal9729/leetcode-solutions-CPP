class Solution {
public:
    double new21Game(int N, int K, int maxPts) {
        if (K == 0) return 1.0;
        if (N >= K - 1 + maxPts) return 1.0;

        vector<double> dp(N + 1, 0.0);
        double probNLessOrEqual = 0.0; // Probability of getting N or less points.
        double windowSum = 1.0; // Sliding window sum

        dp[0] = 1.0;
        for (int i = 1; i <= N; i++) {
            dp[i] = windowSum / maxPts;

            if (i < K)
                windowSum += dp[i];
            else
                probNLessOrEqual += dp[i];
            
            if (i >= maxPts)
                windowSum -= dp[i - maxPts];
        }

        return probNLessOrEqual;
    }
};
