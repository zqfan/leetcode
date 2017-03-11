class Solution(object):                    
    def findRotateSteps(self, ring, key):
        """
        :type ring: str
        :type key: str
        :rtype: int
        """
        def backtracking(ring_pos, key_pos):
            if visited.get(ring_pos, {}).get(key_pos):
                return visited[ring_pos][key_pos]
            if key_pos >= len(key):
                return 0
            min_step = float('inf')
            for i in xrange(len(ring)):
                if ring[i] == key[key_pos]:
                    step = abs(i - ring_pos)
                    step = min(step, len(ring) - step) + 1
                    step += backtracking(i, key_pos + 1)
                    min_step = min(min_step, step)
            return visited.setdefault(ring_pos, {}).setdefault(key_pos, min_step)

        visited = {}
        return backtracking(0, 0)
