class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int m = intervals.size();
        int insertInd = -1;

        vector<int> remove;
        for(int i=0;i<m;i++){
            if(insertInd!=-1){
                if(intervals[insertInd][1] >= intervals[i][0]){
                    intervals[insertInd][1] = max(intervals[insertInd][1], intervals[i][1]);
                    remove.push_back(i);
                }
                else{
                    break;
                }
            }
            else if((intervals[i][0] >= newInterval[0]) || (intervals[i][1] >= newInterval[0])){
                if(intervals[i][0] > newInterval[1]){
                    intervals.insert(intervals.begin()+i, newInterval);
                    insertInd = i;
                    break;
                }
                else{
                    intervals[i][0] = min(intervals[i][0], newInterval[0]);
                    intervals[i][1] = max(intervals[i][1], newInterval[1]);
                }
                insertInd = i;
            }
        }

        if(insertInd==-1){
            intervals.push_back(newInterval);
        }

        int n = remove.size();
        for(int i=n-1;i>=0;i--){
            intervals.erase(intervals.begin()+remove[i]);
        }

        return intervals;
    }
};