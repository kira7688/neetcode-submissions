class Solution {
public:
    int search(vector<int>& nums, int target, int l=0, int r=1111) {
        int m = nums.size();
        if(r==1111){
            r = m-1;
        }
        if(nums[l]==target){
            return l;
        }
        else if(nums[r]==target){
            return r;
        }
        else if(r-l<=1){
            return -1;
        }

        int mid = (l+r)/2;
        if(nums[l]<nums[mid]){
            if(target>=nums[l] && target<=nums[mid]){
                return search(nums, target, l, mid);
            }
            else{
                return search(nums, target, mid+1, r);
            }
        }
        else if(nums[mid+1]<nums[r]){
            if(target>=nums[mid+1] && target<=nums[r]){
                return search(nums, target, mid+1, r);
            }
            else{
                return search(nums, target, l, mid);
            }
        }
    }
};
