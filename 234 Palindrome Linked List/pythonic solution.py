# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def isPalindrome(self, head):
        # type: (ListNode) -> bool
        """
        :type head: ListNode
        :rtype: bool
        """

        lst = []  # type: list
        p = head
        while p is not None:
            lst.append(p.val)
            p = p.next

        return lst == lst[::-1]
