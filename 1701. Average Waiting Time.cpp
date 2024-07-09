class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) 
    {
        double sum = 0.0, cur = 0, n = customers.size();
        for(auto vec:customers)
        {
            if(vec[0] > cur)
            {
                sum += vec[1];
                cur = vec[0] + vec[1];
            }
            else 
            {
                cur += vec[1];
                sum += cur - vec[0];
            }
        }
        return sum/customers.size();
    }
};
