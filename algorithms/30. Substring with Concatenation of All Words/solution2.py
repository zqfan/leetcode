class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        indices = []
        words_count = collections.defaultdict(int)
        for w in words:
            words_count[w] += 1
        cur_count = collections.defaultdict(int)
        l = len(words[0])
        for i in range(len(s)-len(words)*l+1):
            cur_count.clear()
            j = i
            while j < i + len(words)*l:
                ss = s[j:j+l]
                cur_count[ss] += 1
                if ss not in words_count or cur_count[ss] > words_count[ss]:
                    break
                j += l
            else:
                indices.append(i)
        return indices
