class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """

        m = len(nums1)
        n = len(nums2)

        # handle emtpy list
        if m == 0:  # nums1 is empty
            if n % 2 == 0:
                return float((nums2[n // 2] + nums2[n // 2 - 1]) / 2)
            else:
                return float(nums2[n // 2])

        if n == 0:  # nums2 is emtpy
            if m % 2 == 0:
                return float((nums1[m // 2] + nums1[m // 2 - 1]) / 2)
            else:
                return float(nums1[m // 2])

        # do real thing
        if (m + n) % 2 == 0:  # even
            m1 = self._find_at((m + n) // 2, nums1, nums2)
            m2 = self._find_at((m + n) // 2 - 1, nums1, nums2)
            return (m1 + m2) / 2
        else:  # odd
            m = self._find_at((m + n) // 2, nums1, nums2)
            return m

    def _find_at(self, loc, nums1, nums2):
        import bisect

        def get_range(a, x):
            'Get the range of x locate in a'
            i = bisect.bisect_left(a, x)
            j = bisect.bisect_right(a, x)

            return (i, j)

        len1 = len(nums1)
        len2 = len(nums2)

        result = 0

        x = min((nums1[0], nums2[0]))
        while True:
            begin1, end1 = get_range(nums1, x)
            begin2, end2 = get_range(nums2, x)

            if begin1 + begin2 <= loc < end1 + end2:
                result = x
                break
            else:
                if end1 != len1:
                    if end2 != len2:
                        x = min((nums1[end1], nums2[end2]))
                    else:
                        x = nums1[end1]
                else:
                    if end2 != len2:
                        x = nums2[end2]
                    else:
                        x = None  # impossible



        return float(result)
