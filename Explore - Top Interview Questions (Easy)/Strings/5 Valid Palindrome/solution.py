class Solution:
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """

        s_ = [c for c in s.lower() if c.isalpha() or c.isdigit()]
        len_ = len(s_)
        return s_[:len_ // 2] == list(reversed(s_[(len_ + 1) // 2:]))
