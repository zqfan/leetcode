class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        // learned from jiah: use a trick to generate combination
        unordered_map<int, int> maskCnt;
        for (auto & w : words) {
            ++maskCnt[getMask(w)];
        }
        vector<int> answer;
        for (auto & p : puzzles) {
            int mask = getMask(p);
            int initMask = 1 << (p[0] - 'a');
            int cnt = 0;
            for (int i = mask; i > 0; i = (i - 1) & mask) {
                if ((initMask & i) && maskCnt.count(i)) {
                    cnt += maskCnt[i];
                }
            }
            answer.push_back(cnt);
        }
        return answer;
    }

    int getMask(string & s) {
        int mask = 0;
        for (char c : s) {
            mask |= 1 << (c - 'a');
        }
        return mask;
    }
};
