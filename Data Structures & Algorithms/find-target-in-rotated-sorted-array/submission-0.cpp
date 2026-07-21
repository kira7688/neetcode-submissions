class Solution {
public:
    int search(vector<int>& nums, int target) {
        int m = nums.size();

        int pos = -1;
        int l = 0, r = m-1, mid;
        while(l<r && r>=0){
            mid = (l+r)/2;
            if(target==nums[mid]){
                pos = mid;
                break;
            }
            else if(target>nums[mid]){
                if(nums[r]>=nums[mid]){
                    if(target<=nums[r]){
                        l = mid+1;
                    }
                    else{
                        r = mid-1;
                    }
                }
                else{
                    l = mid+1;
                }
            }
            else{
                if(nums[mid]>=nums[l]){
                    if(target>=nums[l]){
                        r = mid-1;
                    }
                    else{
                        l = mid+1;
                    }
                }
                else{
                    r = mid-1;
                }
                
            }
        }
        if(pos==-1){
            if(r>=0 && target==nums[r]){
                pos = r;
            }
        }

        return pos;
    }
};