#include <iostream>
#include <list>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // not empty, the two node is not null

        auto result = new ListNode(l1->val + l2->val);
        auto prevNode = result;
        int nextNum = 0;

        while (l1->next || l2->next || prevNode->val >= 10)
        {
            nextNum = (l1->next ? l1->next->val : 0) + (l2->next ? l2->next->val : 0);

            // carry check
            if (prevNode->val >= 10)
            {
                prevNode->val -= 10;
                nextNum += 1;
            }
            prevNode->next = new ListNode(nextNum);

            prevNode = prevNode->next;
            l1 = l1->next ? l1->next : l1;
            l2 = l2->next ? l2->next : l2;
        }

        return result;
    }
};

ListNode *int2ListNode(int x)
{
    auto result = new ListNode(x % 10);
    auto resultNode = result;

    while (x / 10 > 0)
    {
        x /= 10;
        resultNode->next = new ListNode(x % 10);
        resultNode = resultNode->next;
    }
    return result;
}

void printListNode(ListNode *l)
{
    using namespace std;

    while (l != nullptr)
    {
        cout << l->val << ", ";
        l = l->next;
    }
    cout << endl;
}

void printNumber(ListNode *l)
{
    using namespace std;

    int x = 0;
    int mul = 1;
    while (l != nullptr)
    {
        x += l->val * mul;
        mul *= 10;
        l = l->next;
    }
    cout << x << endl;
}

void freeListNode(ListNode *l)
{
    while (l != nullptr)
    {
        auto p = l;
        l = l->next;
        delete p;
    }
}

void freeListNodes(std::list<ListNode *> llist)
{
    for (auto l : llist)
    {
        freeListNode(l);
    }
}

int main()
{
    ListNode *l1, *l2, *result;
    auto solution = Solution();
    // first sample
    l1 = int2ListNode(342);
    l2 = int2ListNode(465);

    printListNode(l1);
    printListNode(l2);

    result = solution.addTwoNumbers(l1, l2);
    printListNode(result);

    freeListNodes({l1, l2, result});

    // second sample
    l1 = int2ListNode(0);
    l2 = int2ListNode(465);

    printListNode(l1);
    printListNode(l2);

    result = solution.addTwoNumbers(l1, l2);
    printListNode(result);

    freeListNodes({l1, l2, result});

    // third sample
    l1 = int2ListNode(342);
    l2 = int2ListNode(0);

    printListNode(l1);
    printListNode(l2);

    result = solution.addTwoNumbers(l1, l2);
    printListNode(result);

    freeListNodes({l1, l2, result});

    // forth sample
    l1 = int2ListNode(5);
    l2 = int2ListNode(5);

    printListNode(l1);
    printListNode(l2);

    result = solution.addTwoNumbers(l1, l2);
    printListNode(result);

    freeListNodes({l1, l2, result});

    // fifth sample
    l1 = int2ListNode(1);
    l2 = int2ListNode(99);

    printListNode(l1);
    printListNode(l2);

    result = solution.addTwoNumbers(l1, l2);
    printListNode(result);

    freeListNodes({l1, l2, result});

    // sixth sample
    l1 = int2ListNode(0);
    l2 = int2ListNode(0);

    printListNode(l1);
    printListNode(l2);

    result = solution.addTwoNumbers(l1, l2);
    printListNode(result);

    freeListNodes({l1, l2, result});

    return 0;
}