class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        partition_arr = []
        partition = []
        def is_palindrome(s):
            for i in range(len(s)/2):
                if s[i] != s[-i-1]:
                    return False
            return True
        def dfs(start):
            if start == len(s):
                partition_arr.append(partition[:])
                return
            for i in range(start, len(s)):
                ss = s[start:i+1]
                if is_palindrome(ss):
                    partition.append(ss)
                    dfs(i+1)
                    partition.pop()
        dfs(0)
        return partition_arr
