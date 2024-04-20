class Solution {
    private:
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
    sort(nums.begin(), nums.end()); // sort the array first
    do {
        result.push_back(nums); // add the current permutation to the result
    } while (next_permutation(nums.begin(), nums.end())); // generate the next permutation
    return result;

    }
        
    
};