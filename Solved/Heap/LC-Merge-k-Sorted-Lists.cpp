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

    struct ListNodeComparator
    {
        bool operator()(const ListNode *a, const ListNode *b) const
        {
            return a->val > b->val;
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        priority_queue<ListNode *, vector<ListNode *>, ListNodeComparator> pq;

        for (auto &x : lists)
        {
            ListNode *temp = x;

            while (temp)
            {
                pq.push(temp);
                temp = temp->next;
            }
        }

        ListNode *head = NULL, *t = NULL;

        while (!pq.empty())
        {
            ListNode *temp = new ListNode(pq.top()->val);
            pq.pop();

            if (head)
            {
                t->next = temp;
                t = t->next;
            }
            else
            {
                head = temp;
                t = head;
            }
        }

        return head;
    }
};