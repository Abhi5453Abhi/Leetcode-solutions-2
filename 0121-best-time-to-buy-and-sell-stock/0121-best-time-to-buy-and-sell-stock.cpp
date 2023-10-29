class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxAns = 0;
        vector<int> left(prices.size());
        vector<int> right(prices.size());
        int mini = prices[0];
        left[0] = mini;
        for(int i=1;i<prices.size();i++){
            mini = min(mini, prices[i]);
            left[i] = mini;
        }
        int maxi = prices[prices.size()-1];
        right[prices.size()-1] = maxi;
        for(int i=prices.size()-2;i>=0;i--){
            maxi = max(maxi, prices[i]);
            right[i] = maxi;
        }
        for(int i=0;i<prices.size();i++){
            maxAns = max(maxAns, right[i] - left[i]);
        }
        return maxAns;
    }
};