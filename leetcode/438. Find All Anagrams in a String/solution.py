class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        if not s or len(s) < len(p):
            return []

        finger_p = {}
        for c in p:
            finger_p[c] = finger_p.get(c, 0) + 1

        finger_s = {}
        for i in range(len(p)-1):
            finger_s[s[i]] = finger_s.get(s[i], 0) + 1

        indices = []
        for i in range(len(p)-1, len(s)):
            finger_s[s[i]] = finger_s.get(s[i], 0) + 1
            if finger_s == finger_p:
                indices.append(i-len(p)+1)
            finger_s[s[i-len(p)+1]] -= 1
            if finger_s[s[i-len(p)+1]] == 0:
                finger_s.pop(s[i-len(p)+1])

        return indices
