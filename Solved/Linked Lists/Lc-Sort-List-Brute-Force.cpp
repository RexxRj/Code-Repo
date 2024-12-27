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

    struct compare
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };

public:
    ListNode *sortList(ListNode *head)
    {

        priority_queue<ListNode *, vector<ListNode *>, compare> pq;

        while (head)
        {

            pq.push(head);
            head = head->next;
        }

        head = NULL;
        ListNode *temp = NULL;

        while (!pq.empty())
        {
            if (head == NULL)
            {
                head = pq.top();
                temp = head;
            }
            else
            {
                temp->next = pq.top();
                temp = temp->next;
            }
            cout << temp->val << endl;
            pq.pop();
        }

        if (temp)
            temp->next = NULL;

        return head;
    }
};