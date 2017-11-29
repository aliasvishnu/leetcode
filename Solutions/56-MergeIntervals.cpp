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
    vector<Interval> answer;

    vector<Interval> merge(vector<Interval>& intervals) {
        int len = intervals.size();
        cout << len << endl;
        cout << "Here\n";

        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b){
            if ((a.start < b.start) || (a.start == b.start && a.end < b.end)) return true;
            else return false;
        });
        cout << "Here3\n";
        if (len == 0)  return answer;
        int start = intervals[0].start, end = intervals[0].end;

        int i = 0;
        cout << "Here 2\n";
        while(i < len){

            if(i < len-1 && intervals[i+1].start <= end){
                end = (end < intervals[i+1].end)? intervals[i+1].end: end;
                i += 1;
            }else{
                cout << "Pushing " << start << " ,  " << end << " : " << len << endl;
                answer.push_back(Interval(start, end));
                i += 1;
                if(i < len){
                    start = intervals[i].start;
                    end = intervals[i].end;
                }
            }
        }
        return answer;
    }
};
