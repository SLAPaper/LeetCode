class Solution:
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """

        return min((s.index(l) for l in 'abcdefghijklmnopqrstuvwxyz' if s.count(l) == 1), default = -1)

        # more generic solution:
        # return min((s.index(l) for l in set(s) if s.count(l) == 1), default = -1)
