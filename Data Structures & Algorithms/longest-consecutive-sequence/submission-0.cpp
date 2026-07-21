class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int m = nums.size();

        if(!m){
            return 0;
        }

        int up, down, max_conse = 1;
        unordered_set<int> check;
        for(int num: nums){
            check.insert(num);
        }

        
        bool upc, downc;
        for(int num: nums){
            if(!check.count(num)){
                continue;
            }
            check.erase(num);
            up = 0, down = 0;
            upc = true, downc = true;
            for(int i=1;i<m;i++){
                if(upc && check.count(num+i)){
                    up++;
                    check.erase(num+i);
                }
                else{
                    upc = false;
                }
                if(downc && check.count(num-i)){
                    down++;
                    check.erase(num-i);
                }
                else{
                    downc = false;
                }
                if(!upc && !downc){
                    break;
                }
            }
            max_conse = max(max_conse, 1+up+down);
        }

        return max_conse;
    }
};