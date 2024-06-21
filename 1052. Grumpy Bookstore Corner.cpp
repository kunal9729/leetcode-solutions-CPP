class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int l = 0;
        int r = minutes - 1;
        int fl = 0;
        int fr = r;
        int maxprof = 0;
        for(int i = 0; i<=r; i++){
            if(grumpy[i] == 1){
                maxprof += customers[i];
            }
        }
        r++;
        int prof = maxprof;
        while(r<customers.size()){
            if(grumpy[r] == 1 && grumpy[l] == 1){
                prof += (customers[r] - customers[l]);
            }else if(grumpy[r] == 1 && grumpy[l] == 0){
                prof += (customers[r]);
            }else if(grumpy[r] == 0 && grumpy[l] == 1){
                prof -= customers[l];
            }
            if(prof > maxprof){
                fl = l+1;
                fr = r;
                maxprof = prof;
            }
            l++;
            r++;
        }
        int res = 0;
        for(int i=0; i<customers.size(); i++){
            if(grumpy[i] == 0)res += customers[i];
        }
        for(int i=fl; i<=fr; i++){
            if(grumpy[i] == 1)res += customers[i];
        }
        return res;
    }
};
