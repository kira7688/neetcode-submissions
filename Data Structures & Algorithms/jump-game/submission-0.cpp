class Solution {
public:
    bool canJump(vector<int>& nums) {
        int m = nums.size();
        
        int start = 0, end = 0;
        while(start<=end){
            end = max(end, start+nums[start]);
            if(end>=m-1){
                return true;
            }
            start++;
        }

        return false;
    }
};