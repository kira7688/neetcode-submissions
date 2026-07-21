class Solution {
public:
    static bool comparator(vector<int> first, vector<int> second){
        return first[0] < second[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int m = intervals.size();
        if(m==1){
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), comparator);
        int start = intervals[0][0], end = intervals[0][1];
        vector<vector<int>> ans;
        for(int i=1;i<m;i++){
            if(end < intervals[i][0]){
                ans.push_back({start, end});
                start = intervals[i][0];
            }
            end = max(end, intervals[i][1]);
        }
        ans.push_back({start, end});

        return ans;
    }
};