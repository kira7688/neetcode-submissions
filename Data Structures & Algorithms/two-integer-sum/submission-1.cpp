class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int m = nums.size();
        unordered_map<int,int> hashMap;

        vector<int> ans;
        for(int i=0;i<m;i++){
            if(hashMap.count(target-nums[i])){
                ans.push_back(hashMap[target-nums[i]]);
                ans.push_back(i);
                break;
            }
            hashMap[nums[i]] = i;
        }

        return ans;
    }
};