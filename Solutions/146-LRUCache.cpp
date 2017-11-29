// NOTE
#include <typeinfo>

struct custom{
    int key;
    int value;
    list<int>:: iterator loc;
};
class LRUCache {
public:
    unordered_map<int, struct custom *> cache;
    list<int> lst;
    int filled;
    int maxCapacity;
    LRUCache(int capacity) {
        maxCapacity = capacity;
        filled = 0;
    }

    int get(int key) {
        // Check cache for existence
        // cout << "Looking for " << key << endl;
        if(cache.find(key) == cache.end()) return -1;
        else{
            auto *it = cache[key];
            int val = it->value;
            // cout << it->loc;
            lst.erase(it->loc);
            lst.push_back(key);

            // Update the cache
            // cout << typeid(cache[key]).name();
            // cout << typeid(lst.back()).name();
            cache[key]->loc = (--lst.end());
            // cout << "Found " << key << endl;
            return val;
        }
    }

    void put(int key, int value) {
        //  If filled, evict lru element
        if(cache.find(key) == cache.end()){
            if(filled == maxCapacity){

                int k = *(lst.begin());
                lst.erase(lst.begin());
                cache.erase(k);
                // cout << "Removing " << k << endl;
                filled--;
            }
        }else{
            list<int>:: iterator j = cache[key]->loc;
            lst.erase(j);
            cache.erase(key);
            filled--;
        }

            lst.push_back(key);
            struct custom *temp = (struct custom*)malloc(sizeof(struct custom));
            temp->value = value;
            temp->key = key;
            temp->loc = (--lst.end());

            cache[key] = temp;
            filled++;
            // cout << "Inserting " << key << ", " << value <<endl;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
