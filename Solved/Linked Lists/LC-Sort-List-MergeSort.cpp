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

    ListNode *mergeSortLL(ListNode *left, ListNode *right)
    {
        ListNode *head = NULL, *temp = NULL;

        while (left && right)
        {
            if (left->val < right->val)
            {
                if (head == NULL)
                {
                    head = left;
                    temp = head;
                }
                else
                {
                    temp->next = left;
                    temp = temp->next;
                }

                left = left->next;
            }
            else
            {
                if (head == NULL)
                {
                    head = right;
                    temp = head;
                }
                else
                {
                    temp->next = right;
                    temp = temp->next;
                }

                right = right->next;
            }
        }

        while (left)
        {
            if (head == NULL)
            {
                head = left;
                temp = head;
            }
            else
            {
                temp->next = left;
                temp = temp->next;
            }
            left = left->next;
        }

        while (right)
        {
            if (head == NULL)
            {
                head = right;
                temp = head;
            }
            else
            {
                temp->next = right;
                temp = temp->next;
            }

            right = right->next;
        }

        if (temp)
            temp->next = NULL;

        return head;
    }

public:
    ListNode *sortList(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode *fast = head->next, *slow = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        // cout<<slow->val<<endl;
        fast = slow->next;
        slow->next = NULL;

        ListNode *left = sortList(head);
        ListNode *right = sortList(fast);

        return mergeSortLL(left, right);
    }
};