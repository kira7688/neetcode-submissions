class Solution {
public:
    static bool comparator(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int m = intervals.size();
        if(m==1){
            return 0;
        }

        sort(intervals.begin(), intervals.end(), comparator);
        
        int ans = 0;
        for(int i=1;i<m;i++){
            if(intervals[i-1][1] > intervals[i][0]){
                intervals[i][1] = min(intervals[i][1], intervals[i-1][1]);
                ans++;
            }
        }

        return ans;
    }
};