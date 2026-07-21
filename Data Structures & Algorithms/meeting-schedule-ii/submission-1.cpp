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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> times(1000001, 0);
        int maxOverlap = 0;
        for(Interval meeting: intervals){
            for(int i=meeting.start;i<meeting.end;i++){
                times[i]++;
                maxOverlap = max(maxOverlap, times[i]);
            }
        }
        // for(Interval meeting: intervals){
        //     if(times[meeting.start])
        //         times[meeting.start]++;
        //     }
        //     if(times[meeting.end])
        //         times[meeting.start]++;
        //     }
        // }
        

        return maxOverlap;
    }
};
