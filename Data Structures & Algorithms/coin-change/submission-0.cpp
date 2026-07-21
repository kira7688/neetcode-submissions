class Solution {
public:
    int coinChangeMin(vector<int>& coins, int amount, vector<int>& memoize){
        if(amount<0){
            return INT_MAX-1;
        }

        if(memoize[amount]!=INT_MAX){
            return memoize[amount];
        }

        int res = INT_MAX;
        for(auto coin: coins){
            res = min(res, coinChangeMin(coins, amount-coin, memoize));
        }

        if(res<INT_MAX-1){
            res = res+1;
        }
        else if(res==INT_MAX){
            res = INT_MAX-1;
        }

        memoize[amount] = res;

        return memoize[amount];
        
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        
        vector<int> memoize(amount+1, INT_MAX);
        memoize[0] = 0;

        coinChangeMin(coins, amount, memoize);

        if(memoize[amount]==INT_MAX || memoize[amount]==INT_MAX-1){
            memoize[amount] = -1;
        }

        return memoize[amount];
    }
};