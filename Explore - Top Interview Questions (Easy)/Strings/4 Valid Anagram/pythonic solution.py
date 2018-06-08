class Solution:
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        return all(s.count(l) == t.count(l) for l in "abcdefghijklmnopqrstuvwxyz")

        # generic solution:
        return all(s.count(l) == t.count(l) for l in set(s) | set(t))
