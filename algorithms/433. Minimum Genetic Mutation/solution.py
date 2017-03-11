class Solution(object):
    def minMutation(self, start, end, bank):
        """
        :type start: str
        :type end: str
        :type bank: List[str]
        :rtype: int
        """
        def dfs(start):
            if start in mem:
                return mem[start]
            mem[start] = float('inf')
            for i in xrange(len(start)):
                for j in ['A', 'C', 'G', 'T']:
                    s = start[:i] + j + start[i+1:]
                    if s in bank:
                        mem[start] = min(mem[start], dfs(s) + 1)
            return mem[start]
        
        mem = {end: 0}
        bank = set(bank)
        r = dfs(start)
        return r if r != float('inf') else -1
