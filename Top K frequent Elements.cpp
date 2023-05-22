class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (int num : nums) mp[num]++;
        priority_queue<pair<int,int>> m;
        for (auto i : mp) m.push({i.second, i.first});
        vector<int> res;
        while (k--) res.push_back(m.top().second), m.pop();
        return res;
    }
};
