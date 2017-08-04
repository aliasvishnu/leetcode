class Solution {
public:
    struct node{
        int val;
        int pos;

        node(int a, int b){
            val = a;
            pos = b;
        }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> answer;
        vector<int> nge(len, -1);
        if (len == 0 || k == 0) return answer;

        for(int i = 0; i < len; i++){
            nge[i] = i;
        }
        stack<struct node*> stk;
        //Solve Next greater element problem in leetcode O(n) solution
        for(int i = 0; i < len; i++){
            if(stk.empty()) stk.push(new node(nums[i], i));
            else{
                while(!stk.empty() && stk.top()->val < nums[i]){
                    nge[stk.top()->pos] = i;
                    stk.pop();
                 }
                stk.push(new node(nums[i], i));
            }
        }

        int maxind = len+1;  //setting high value just for base case
        for(int i = 0; i < len-k+1; i++){
            int windowMax = i+k-1;
            if(maxind > windowMax || maxind < i)
                maxind = i;

            while(nge[maxind] <= windowMax && nge[maxind] != maxind) maxind = nge[maxind];
            answer.push_back(nums[maxind]);
        }
        return answer;
    }
};
