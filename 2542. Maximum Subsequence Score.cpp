class Solution {
public:
    long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++) {
            pairs[i] = {nums2[i], nums1[i]};
        }
        sort(pairs.begin(), pairs.end(), greater<pair<int, int>>());
        priority_queue<int, vector<int>, greater<int>> pq;
        long res = 0, totalSum = 0;
        for (const auto& pair : pairs) {
            pq.push(pair.second);
            totalSum += pair.second;
            if (pq.size() > k) {
                totalSum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                res = max(res, totalSum * pair.first);
            }
        }
        return res;
    }
};
