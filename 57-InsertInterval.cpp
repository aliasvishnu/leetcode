/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#include <algorithm>
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval niv) {
        // if(niv.start == niv.end) return intervals;

        sort(intervals.begin(), intervals.end(), [this](Interval a, Interval b){
           return a.start < b.start;
        });
        int ibegin = -1, iend = -1, start = niv.start, end = niv.end;

        int len = intervals.size();
        for(int i = 0; i < len; i++){
            if((niv.start >= intervals[i].start && niv.start <= intervals[i].end) ||
               (intervals[i].start >= niv.start && intervals[i].start <= niv.end)){
                   if(ibegin == -1){
                        ibegin = i;
                        start = (niv.start <= intervals[i].start)? niv.start:intervals[i].start;
                   }
               }

            if((niv.end >= intervals[i].start && niv.end <= intervals[i].end) ||
               (intervals[i].end >= niv.start && intervals[i].end <= niv.end)){
                   iend = i;
                   end = (niv.end >= intervals[i].end)? niv.end:intervals[i].end;
               }
        }
        // cout << ibegin << " " << iend << endl;
        if(ibegin != -1) intervals.erase(intervals.begin()+ibegin, intervals.begin()+iend+1);

        Interval *temp = new Interval(start, end);
        intervals.push_back(*temp);
        // cout << start << ", " << end;

        sort(intervals.begin(), intervals.end(), [this](Interval a, Interval b){
           return a.start < b.start;
        });

        return intervals;
    }
};
