// Memory constraint, but no time constraint,
// O(1) memory, O(n) time

class Solution {
public:
    vector<int> nms;
    int len;
    Solution(vector<int> nums) {
        vector<int> temp(nums);
        // sort(temp.begin(), temp.end());
        swap(nms, temp);
        len = nums.size();
    }

    int pick(int target) {
        int count = 0;
        for(int i = 0; i < len; i++){
           if(nms[i] == target) count++;
        }

        int c = (rand() % count)+1;

        for(int i = 0; i < len; i++){
            if(nms[i] == target){
                c--;
                if(c == 0) return i;
            }
        }
        return -1;
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
