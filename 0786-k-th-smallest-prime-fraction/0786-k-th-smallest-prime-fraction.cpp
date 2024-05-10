class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> res;
        priority_queue<pair<double,vector<int>>,vector<pair<double,vector<int>>>,greater<pair<double,vector<int>>>> pq;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n;j++){
                pq.push({(double)arr[i]/arr[j],{arr[i],arr[j]}});
            }
        }
        while(--k){
            pq.pop();
        }
        return pq.top().second;
    }
};