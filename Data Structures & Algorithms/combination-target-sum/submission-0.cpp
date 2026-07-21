class Solution {
public:
    void combinations(vector<int>& candidates, int target, int start, vector<int> comb, vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(comb);
            return;
        }


        int new_target;
        comb.push_back(-1);
        for(int i=start;i<candidates.size();i++){
            new_target = target - candidates[i];
            if(new_target<0){
                return;
            }
            comb[comb.size()-1] = candidates[i];
            combinations(candidates, new_target, i, comb, ans);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;

        sort(candidates.begin(), candidates.end());

        combinations(candidates, target, 0, vector<int>(), ans);

        return ans;
    }
};