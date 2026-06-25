class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int cost = prices[0];
        for(int i = 1 ; i<prices.size() ; i++)
        {
            int profit = prices[i] - cost;
            maxi = max(maxi,profit);
            cost = min(cost,prices[i]);
        }
        return maxi;
    }
};
