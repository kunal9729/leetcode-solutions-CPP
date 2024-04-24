class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    int i = 0; // index of the last non-zero element
    int j = 0; // index of the current element
    while (j < nums.size()) {
        if (nums[j] != 0) {
            if (i != j) {
                swap(nums[i], nums[j]);
            }
            i++;
        }
        j++;
    }
}

};