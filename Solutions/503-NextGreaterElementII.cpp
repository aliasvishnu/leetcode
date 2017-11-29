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

    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int> answer(len, -1);
        stack<struct node*> stk;

        for(int i = 0; i < 2*len; i++){
            if(stk.empty()) stk.push(new node(nums[i%len], i));
            else{
                while(!stk.empty() && stk.top()->val < nums[i%len]){
                    answer[stk.top()->pos%len] = nums[(i%len)];
                    stk.pop();
                 }
                stk.push(new node(nums[i%len], i));
            }
        }
        return answer;
    }
};
