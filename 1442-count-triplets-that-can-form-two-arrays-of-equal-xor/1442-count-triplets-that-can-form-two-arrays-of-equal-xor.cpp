class Solution {
public:
    int countTriplets(vector<int>& a) {
        int count = 0;
        int n = a.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a1 = 0;
                for (int k = i; k < j; k++) {
                    a1 ^= a[k];
                }
                
                int b = 0;
                for (int k = j; k < n; k++) {
                    b ^= a[k];
                    if (a1 == b) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};