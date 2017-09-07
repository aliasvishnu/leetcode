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
    vector<Interval *> slots;
    int answer = 0;

    void accomodate(Interval *iv){
        for(int i = 0; i < answer; i++){
            if(slots[i] != NULL && slots[i]->end <= iv->start) slots[i] = NULL;
        }

        for(int i = 0; i < answer; i++){
            if(slots[i] == NULL){
                slots[i] = iv;
                return;
            }
        }

        slots.push_back(iv);
        answer++;
    }

    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){
            return (a.start < b.start || (a.start == b.start && a.end < b.end));
        });

        int len = intervals.size();
        for(int i = 0; i < len; i++){
            accomodate(&intervals[i]);
        }

        return answer;
    }
};
