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
    bool isPalindrome(ListNode *head)
    {

        ListNode *fast = head, *slow = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        stack<int> st;
        queue<int> q;

        if (fast != NULL)
            slow = slow->next;
        fast = head;

        while (slow)
        {
            st.push(fast->val);
            q.push(slow->val);
            fast = fast->next;
            slow = slow->next;
        }

        while (!st.empty())
        {
            if (st.top() != q.front())
                return false;
            st.pop();
            q.pop();
        }

        return true;
    }
};
