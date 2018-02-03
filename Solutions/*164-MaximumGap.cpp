#include <math.h>
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int len = nums.size();

        if(len < 2) return 0;

        vector<int> mins (len, INT_MAX);
        vector<int> maxs (len, INT_MIN);

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        int gap = ceil( (mx - mn)*1.0 / (len-1) );

        for(int i: nums){
            if(i == mn || i == mx) continue;

            int ind = (i - mn)/gap;

            mins[ind] = (mins[ind] < i)? mins[ind]: i;
            maxs[ind] = (maxs[ind] > i)? maxs[ind]: i;
        }

        int prev = mn, answer = 0;

        for(int i = 0; i < len-1; i++){
            if(mins[i] == INT_MAX) continue;

            answer = max(answer, mins[i]-prev);
            prev = maxs[i];
        }

        answer = max(answer, mx-prev);
        return answer;
    }
};
