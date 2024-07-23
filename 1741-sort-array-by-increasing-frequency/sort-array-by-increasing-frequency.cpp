class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> fq;


        for(int num : nums) {
            fq[num]++;
        }


        sort(nums.begin(), nums.end(), [&] (int n1, int n2){
            if(fq[n1] != fq[n2]) {
                return fq[n1] < fq[n2];
            } else {
                return n2 < n1;
            }
        });

        return nums;
        
    }
};