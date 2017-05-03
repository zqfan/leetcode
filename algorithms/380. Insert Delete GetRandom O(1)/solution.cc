class RandomizedSet {
    vector<int> values;
    unordered_map<int, int> indices;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if ( indices.find(val) != indices.end() ) {
            return false;
        }
        indices[val] = values.size();
        values.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if ( indices.find(val) == indices.end() ) {
            return false;
        }
        int delIdx = indices[val], lastIdx = values.size() - 1;
        values[delIdx] = values[lastIdx];
        indices[values[lastIdx]] = delIdx;
        indices.erase(val);
        values.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return values[rand() % values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

// 18 / 18 test cases passed.
// Status: Accepted
// Runtime: 52 ms
// beats 68.84 %
