from main import Solution

s = Solution()

print(s.findMedianSortedArrays([1, 3], [2]), 2.0)
print(s.findMedianSortedArrays([1, 2], [3, 4]), 2.5)
print(s.findMedianSortedArrays([2], []), 2.0)
print(s.findMedianSortedArrays([], [2, 3]), 2.5)
print(s.findMedianSortedArrays([3, 4], []), 3.5)
print(s.findMedianSortedArrays([1, 2, 3], []), 2.0)
print(s.findMedianSortedArrays([1, 1, 3, 3], [1, 1, 3, 3]), 2.0)
print(s.findMedianSortedArrays([2], [1]), 1.5)
