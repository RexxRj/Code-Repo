/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode *cur = head, *shead = head->next, *next = head->next;
        int flg = 0;

        while (cur && cur->next)
        {
            next = cur->next;
            if (next->next == NULL)
            {
                if (flg)
                {
                    cur->next = next->next;
                    next->next = shead;
                    break;
                }
                else
                {
                    cur->next = shead;
                    break;
                }
            }
            cur->next = next->next;
            cur = next;
            flg ^= 1;
        }

        return head;
    }
};
