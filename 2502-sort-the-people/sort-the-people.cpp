class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> mp;
        for(int i=0; i<names.size(); i++) {
            mp[heights[i]] = names[i];
        }

        sort(heights.begin(), heights.end());
        vector<string> result(heights.size());
        int idx = 0;

        for(int i = heights.size()-1; i>= 0; i--) {
            result[idx] = mp[heights[i]];
            idx++;
        }


        return result;
        
    }
};