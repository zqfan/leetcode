class Twitter(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.users = {}
        self.timestamp = 0
        self.MAX_FEED = 10

    def _get_or_create_user(self, userId):
        if userId not in self.users:
            self.users[userId] = {
                'followers': {userId},
                'followees': {userId},
                'tweets': [],
                'feed': collections.deque()
            }
        return self.users[userId]

    def postTweet(self, userId, tweetId):
        """
        Compose a new tweet.
        :type userId: int
        :type tweetId: int
        :rtype: void
        """
        self.timestamp += 1
        t = (self.timestamp, tweetId)
        user = self._get_or_create_user(userId)
        user['tweets'].append(t)
        for follower in user['followers']:
            if len(self.users[follower]['feed']) >= self.MAX_FEED:
                self.users[follower]['feed'].pop()
            self.users[follower]['feed'].appendleft(t)

    def getNewsFeed(self, userId):
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        :type userId: int
        :rtype: List[int]
        """
        user = self._get_or_create_user(userId)
        return [f[1] for f in user['feed']]

    def follow(self, followerId, followeeId):
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """
        if followerId == followeeId:
            return
        followee = self._get_or_create_user(followeeId)
        if followerId in followee['followers']:
            return
        followee['followers'].add(followerId)
        follower = self._get_or_create_user(followerId)
        follower['followees'].add(followeeId)

        feed = follower['feed']
        if len(feed) == 0 or not followee['tweets']:
            for t in followee['tweets'][-self.MAX_FEED:]:
                feed.appendleft(t)
        else:
            follower['feed'] = collections.deque()
            i = len(followee['tweets']) - 1
            while len(follower['feed']) < self.MAX_FEED:
                if feed and i >= 0:
                    if feed[0][0] > followee['tweets'][i][0]:
                        follower['feed'].append(feed.popleft())
                    else:
                        follower['feed'].append(followee['tweets'][i])
                        i -= 1
                elif feed:
                    follower['feed'].append(feed.popleft())
                elif i >= 0:
                    follower['feed'].append(followee['tweets'][i])
                    i -= 1
                else:
                    break

    def unfollow(self, followerId, followeeId):
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """
        if followerId == followeeId:
            return
        followee = self._get_or_create_user(followeeId)
        if followerId not in followee['followers']:
            return
        followee['followers'].remove(followerId)
        follower = self._get_or_create_user(followerId)
        follower['followees'].remove(followeeId)
        follower['feed'] = collections.deque()
        heap = []
        for fid in follower['followees']:
            f = self.users[fid]
            if f['tweets']:
                heap.append((f['tweets'][-1], f['tweets'], len(f['tweets'])-1))
        heapq.heapify(heap)
        while len(follower['feed']) < self.MAX_FEED and heap:
            t = heapq.heappop(heap)
            follower['feed'].append(t[0])
            if t[2] > 0:
                heapq.heappush(heap, (t[1][t[2]-1], t[1], t[2]-1))

# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
