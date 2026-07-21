class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = (n+1)*(n)/2;
        for(int num: nums){
            ans -= num;
        }

        return ans;
    }
};