const long long A=100001;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        bitset<A> hasX=0;
        int B = 0;
        for(int x : nums) {
            hasX[x] = 1;
            B=max(B,x);

        }

        int mxStreak=0;
        for(long long x : nums) {
            int streak = 1;
            for(long long z = x*x; z<=B; z*=z)
            if(hasX[z]) streak++;
            else break;
            mxStreak = max(mxStreak, streak);
            if(mxStreak==5) break;
        }

        return mxStreak<2?-1 : mxStreak;
        
    }
};
