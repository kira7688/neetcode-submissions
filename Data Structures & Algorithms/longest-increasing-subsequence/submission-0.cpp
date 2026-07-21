class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int m = nums.size();

        vector<int> dp(m, 1);

        int sis = 1;
        for(int i=m-2;i>=0;i--){
            for(int j=i+1;j<m;j++){
                if(nums[j] > nums[i]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            sis = max(sis, dp[i]);
        }

        return sis;
    }
};