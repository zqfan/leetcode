class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> answer(queries.size());
        vector<int> wordsFreq(11);
        int freq;
        for (int i = 0; i < words.size(); ++i) {
            freq = getSmallestFrequency(words[i]);
            ++wordsFreq[freq];
        }
        vector<int> sumLargerThanFreq(11);
        for (int i = wordsFreq.size() - 2; i > 0; --i) {
            sumLargerThanFreq[i] = sumLargerThanFreq[i+1] + wordsFreq[i+1]; 
        }
        for (int i = 0; i < queries.size(); ++i) {
            freq = getSmallestFrequency(queries[i]);
            answer[i] = sumLargerThanFreq[freq];
        }
        return answer;
    }
    
    int getSmallestFrequency(string & word) {
        char small = 'z';
        int freq = 0;
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] < small) {
                small = word[i];
                freq = 1;
            } else if (word[i] == small) {
                ++freq;
            }
        }
        return freq;
    }
};
