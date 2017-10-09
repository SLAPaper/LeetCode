class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        max_len = 0
        d = {}  # type: typing.Dict[str, int]

        pi = -1
        for i, c in enumerate(s):
            if c in d:
                pi = max((d[c], pi))
            max_len = max((max_len, i - pi))
            d[c] = i

        return max_len
