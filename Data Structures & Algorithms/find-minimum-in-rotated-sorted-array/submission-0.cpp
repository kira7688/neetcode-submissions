class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1, m;
        if(nums[l]<nums[r]){
            return nums[l];
        }
        while(l<r){
            if(r==l+1){
                return min(nums[l], nums[r]);
            }
            m = (l+r)/2;
            if(nums[m]>nums[l]){
                if(nums[m+1]<nums[m]){
                    return nums[m+1];
                }
                l = m+1;
            }
            else{
                r = m;
            }
        }

        return nums[l];
    }
};