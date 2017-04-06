class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> desc;
        unordered_map<int, int> nextGreater;
        for ( int n : nums ) {
            while ( desc.size() && desc.top() < n ) {
                nextGreater[desc.top()] = n;
                desc.pop();
            }
            desc.push(n);
        }
        vector<int> result;
        for ( int n : findNums ) {
            result.push_back(nextGreater.count(n) ? nextGreater[n] : -1);
        }
        return result;
    }
};
