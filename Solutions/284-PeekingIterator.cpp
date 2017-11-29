class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    vector<int> ::const_iterator it;
    vector<int> ::const_iterator et;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        it = nums.begin();
        et = nums.end();
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return *it;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int ans = *it;
        it++;
        return ans;
	}

	bool hasNext() const {
	    return it != et;
	}
};
