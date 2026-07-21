class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }

        vector<int> money(n);

        money[0] = nums[0];
        money[1] = max(nums[0], nums[1]);

        for(int i=2;i<n;i++){
            money[i] = max(nums[i]+money[i-2], money[i-1]);
        }

        return money[n-1];
    }
};