class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], sum = max(nums[0], 0);//, maxStart= 0, start = 0, maxLen = 1;

        int m = nums.size();
        for(int i=1;i<m;i++){
            sum += nums[i];
            if(sum>maxSum){
                maxSum = sum;
                //maxStart = start;
                //maxLen = i-start+1;
            }
            if(sum<0){
                //start = i+1;
                sum = 0;
            }
        }
        //vector<int> ans(nums.begin()+maxStart, nums.end()+maxStart+maxLen);

        return maxSum;

    }
};