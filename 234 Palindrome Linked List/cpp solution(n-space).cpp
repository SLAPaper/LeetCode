/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <vector>

struct ListNode;

class Solution
{
  public:
    bool isPalindrome(ListNode *head)
    {
        std::vector<int> vec;
        ListNode *p = head;
        while (p != nullptr)
        {
            vec.push_back(p->val);
            p = p->next;
        }

        for (int i = 0; 2 * i < vec.size(); ++i)
        {
            if (vec[i] != vec[vec.size() - i - 1])
            {
                return false;
            }
        }

        return true;
    }
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
