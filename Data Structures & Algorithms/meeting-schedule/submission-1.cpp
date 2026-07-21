/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool comparator(Interval t1, Interval t2){
        return t1.start < t2.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        int m = intervals.size();
        if(!m){
            return true;
        }
        sort(intervals.begin(), intervals.end(), comparator);

        int prev_end = intervals[0].end;
        for(int i=1;i<m;i++){
            if(prev_end > intervals[i].start){
                return false;
            }
            prev_end = intervals[i].end;
        }

        return true;
    }
};
