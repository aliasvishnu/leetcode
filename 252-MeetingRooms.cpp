/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){
            if(a.start < b.start || (a.start == b.start && a.end < b.end)) return true;
            else return false;
        });

        int len = intervals.size();
        for(int i = 0; i < len-1; i++){
            if(intervals[i].end > intervals[i+1].start) return false;
        }
        return true;
    }
};
