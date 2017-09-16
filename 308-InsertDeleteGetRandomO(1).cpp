class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> mp;
    vector<int> vec;

    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val) == mp.end()){
            mp[val] = vec.size();
            vec.push_back(val);
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val) != mp.end()){
            int loc = mp[val];
            swap(vec[loc], vec[vec.size()-1]);
            vec.pop_back();
            mp.erase(val);
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int size = vec.size();
        int index = rand()%size;

        return *(vec.begin()+ind);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
