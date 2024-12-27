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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        ListNode *slow = head, *fast = head;
        int cnt = 1;

        while (cnt != n)
        {
            slow = slow->next;
            cnt++;
        }

        if (slow->next == NULL)
            return head->next;

        ListNode *prev = NULL;

        while (slow->next)
        {
            prev = fast;
            fast = fast->next;
            slow = slow->next;
        }

        prev->next = fast->next;
        return head;
    }
};