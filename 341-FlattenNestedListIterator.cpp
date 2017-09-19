/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    vector<int> answer;
    int i, len;

    void load(vector<NestedInteger> nestedList){
        for(NestedInteger cur: nestedList){
            if(cur.isInteger()) answer.push_back(cur.getInteger());
            else load(cur.getList());
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        load(nestedList);
        i = 0; len = answer.size();
    }

    int next() {
        return answer[i++];
    }

    bool hasNext() {
        return i < len;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
