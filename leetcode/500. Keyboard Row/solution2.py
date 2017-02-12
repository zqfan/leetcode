class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        keyboard = [set('qwertyuiop'), set('asdfghjkl'), set('zxcvbnm')]
        res = []
        for word in words:
            char_set = set(word.lower())
            hit_rows = 0
            for row in keyboard:
                if char_set & row:
                    hit_rows += 1
            if hit_rows == 1:
                res.append(word)
        return res
