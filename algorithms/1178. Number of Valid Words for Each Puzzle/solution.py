class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        counter = collections.Counter(''.join(sorted(set(w))) for w in words)
        answer = []
        for p in puzzles:
            cnt = 0
            for i in range(7):
                for c in itertools.combinations(p[1:], i):
                    cnt += counter[''.join(sorted((p[0],) + c))]
            answer.append(cnt)
        return answer
