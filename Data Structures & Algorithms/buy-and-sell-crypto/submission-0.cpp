class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = INT_MIN;
        int minPrice = prices[0];

        int m = prices.size();
        for(int i=1;i<m;i++){
            maxProfit = max(prices[i]-minPrice, maxProfit);
            minPrice = min(minPrice, prices[i]);
        }
        maxProfit = max(maxProfit, 0);

        return maxProfit;
    }
};
