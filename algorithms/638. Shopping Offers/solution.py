class Solution(object):
    def shoppingOffers(self, price, special, needs):
        """
        :type price: List[int]
        :type special: List[List[int]]
        :type needs: List[int]
        :rtype: int
        """
        # @ franco3
        def dfs(remain, acc):
            if all(x == 0 for x in remain):
                return acc
            elif any( x < 0 for x in remain):
                return float('inf')
            ans = sum(map(lambda x, y: x * y, remain, price))
            for spe in special:
                ans = min(ans, dfs(map(lambda x, y: x - y, remain, spe[:-1]), spe[-1]))
            return ans + acc
        return dfs(needs, 0)

# 53 / 53 test cases passed.
# Status: Accepted
# Runtime: 462 ms
# beats 10.94 %

'''
@ awice
The testcases are weak. This solution TLEs on this case:
[6,6,6,6,6,6]
[[1,0,0,0,0,0,0],[0,1,0,0,0,0,0],[0,0,1,0,0,0,0],[0,0,0,1,0,0,0],[0,0,0,0,1,0,0],[0,0,0,0,0,1,0]]
[6,6,6,6,6,6]
'''
