class Solution {
public:
    int rob(vector<int>& nums) {
        int m = nums.size();
        vector<int> loot(m, 0);

        loot[m-1] = nums[m-1];
        if(m>1){
            loot[m-2] = max(nums[m-2], loot[m-1]);
        }
        for(int i=m-3;i>=0;i--){
            loot[i] = max(nums[i]+loot[i+2], loot[i+1]);
        }

        return loot[0];
        
    }
};
