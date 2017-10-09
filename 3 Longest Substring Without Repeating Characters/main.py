class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        max_len = 0
        subs = ""

        for c in s:
            try:
                i = subs.find(c)
            except ValueError:
                pass
            else:
                subs = subs[i + 1:] if i < len(subs) else ""
            finally:
                subs = subs + c

            l = len(subs)
            max_len = l if l > max_len else max_len

        return max_len
