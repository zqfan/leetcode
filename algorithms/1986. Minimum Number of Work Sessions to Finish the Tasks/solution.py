class Solution:
    def minSessions(self, tasks: List[int], sessionTime: int) -> int:
        # try big number first, to fail fast
        tasks.sort(reverse=True)
        session = []
        self.result = 14

        # backtracking
        def dfs(cur):
            # fail fast, key point to avoid TLE
            if len(session) >= self.result:
                return
            if cur >= len(tasks):
                self.result = len(session)
                return
            # try existed sessions
            for i in range(len(session)):
                if session[i] + tasks[cur] > sessionTime:
                    continue
                session[i] += tasks[cur]
                dfs(cur + 1)
                session[i] -= tasks[cur]
            # try a new session
            session.append(tasks[cur])
            dfs(cur + 1)
            session.pop()
            
        dfs(0)
        return self.result
