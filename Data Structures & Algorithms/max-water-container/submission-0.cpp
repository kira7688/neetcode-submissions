class Solution {
public:
    int maxArea(vector<int>& height) {
        int m = height.size();
        int left = 0, right = m-1;

        int maxAmount = 0;
        while(left<right){
            if(height[left] > height[right]){
                maxAmount = max(maxAmount, height[right]*(right-left));
                right--;
            }
            else{
                maxAmount = max(maxAmount, height[left]*(right-left));
                left++;
            }
        }

        return maxAmount;
    }
};