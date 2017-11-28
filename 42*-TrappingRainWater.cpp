class Solution {
public:
    stack<int> stk;
    vector<int> next;
    int ans = 0;
    unordered_map<int, int> sums;

    void findNextElementIndex(vector<int> &height){
        int len = height.size();

        int count = 0;
        while(count < len){
            if(height[count] == 0){
                count += 1;
                continue;
            }

            if(stk.empty()){
                stk.push(count++);
                continue;
            }else{
                while(!stk.empty() && height[stk.top()] <= height[count]){
                    next[stk.top()] = count;
                    stk.pop();
                }
                stk.push(count++);
            }
        }
        int prev = -1;
        while(!stk.empty()){
            next[stk.top()] = prev;
            prev = stk.top();
            stk.pop();
        }
    }

    void findTrap(vector<int> &height){
        int cur = 0;
        int len = height.size();
        while(cur != -1){
            cout << cur << endl;
            if(height[cur] == 0){
                cur += 1;
                continue;
            }else{
                int sub = 0;
                if(next[cur] == -1){
                    break;
                }

                if(height[cur] > height[next[cur]]){
                    sub = sums[next[cur]]-sums[cur];
                }else{
                    sub = sums[next[cur]-1]-sums[cur-1];
                }

                ans += min(height[cur], height[next[cur]])*(next[cur]-cur)-sub;
                cur = next[cur];
            }

        }
    }

    void prefixSums(vector<int> &height){
        sums[-1] = 0;
        int len = height.size();

        for(int i = 0; i < len; i++){
            sums[i] = height[i]+sums[i-1];
        }
    }
    //  Start here
    int trap(vector<int>& height) {
        int len = height.size();
        if(len <= 1) return 0;

        // Not sure why I did this, just create a new vector of length len.
        for(int i = 0; i < len; i++){
            next.push_back(0);
        }

        // for every element, find the index st. a[cur] <= a[index]
        // Check Next greater element problem if you need to.
        findNextElementIndex(height);

        prefixSums(height);
        findTrap(height);
        return ans;
    }
};
