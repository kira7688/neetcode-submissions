class Solution {
public:

    vector<vector<int>> explore_right(vector<int>& nums, int l, int r, unordered_map<int,int>& hashMap){
        
        vector<vector<int>> ans;
        int target;

        while(l<r-1){
            while(l<r && nums[l+1]==nums[l]){
                l++;
            }
            while(l<r && nums[r-1]==nums[r]){
                r--;
            }
            
            target = -1*(nums[l]+nums[r]);
            if(target < nums[l]){
                r--;
            }
            else if(target > nums[r]){
                return ans;
            }

            if(target==nums[l]){
                if(hashMap[target]>1){
                    ans.push_back({nums[l],target,nums[r]});
                }
                r--;
            }
            else if(target==nums[r]){
                if(hashMap[target]>1){
                    ans.push_back({nums[l],target,nums[r]});
                }
                break;
            }
            else{
                if(hashMap.count(target)){
                    ans.push_back({nums[l],target,nums[r]});
                }
                r--;
            }
        }

        return ans;
    }

    vector<vector<int>> helper(vector<int>& nums, int l, int r, unordered_map<int,int>& hashMap){
        
        vector<vector<int>> ans, dec_r;
        if(hashMap.count(0)){
            if(hashMap[0]>2){
                ans.push_back({0,0,0});
            }
            hashMap[0] = 1;
        }

        int target;

        while(l<r){
            while(l<r && nums[l+1]==nums[l]){
                l++;
            }
            while(l<r && nums[r-1]==nums[r]){
                r--;
            }
            
            target = -1*(nums[l]+nums[r]);

            //cout << nums[l] << " : " << target << " : " << nums[r] << endl;
            if(target < nums[l]){
                r--;
                continue;
            }
            else if(target > nums[r]){
                l++;
                continue;
            }

            if(target==nums[l]){
                if(hashMap[target]>1){
                    ans.push_back({nums[l],target,nums[r]});
                }
                r--;
            }
            else if(target==nums[r]){
                if(hashMap[target]>1){
                    ans.push_back({nums[l],target,nums[r]});
                }
                l++;
            }
            else{
                if(hashMap.count(target)){
                    ans.push_back({nums[l],target,nums[r]});
                }
                dec_r = explore_right(nums, l, r-1, hashMap);
                ans.insert(ans.end(), dec_r.begin(), dec_r.end());
                l++;
            }
        }

        return ans;

    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int m = nums.size();
        sort(nums.begin(), nums.end());

        unordered_map<int,int> hashMap;
        for(int i=0;i<m;i++){
            //cout << nums[i] << " ";
            if(hashMap.count(nums[i])){
                hashMap[nums[i]]++;
            }
            else{
                hashMap[nums[i]] = 1;
            }
        }

        //cout << endl;

        return helper(nums, 0, m-1, hashMap);
    }
};