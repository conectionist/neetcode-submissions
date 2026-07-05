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

struct ListNodeComparator
{
    bool operator()(ListNode* node1, ListNode* node2)
    {
        if(node1 && node2)
            return node1->val > node2->val;

        return (node1 != nullptr);
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;

        ListNode dummy(0);
        ListNode* tail = &dummy;

        priority_queue<ListNode*, vector<ListNode*>, ListNodeComparator> minHeap;

        for(ListNode* node : lists)
            minHeap.push(node);

        while(!minHeap.empty())
        {
            auto* currentNode = minHeap.top();
            minHeap.pop();

            tail->next = new ListNode(currentNode->val);
            tail = tail->next;

            if(currentNode->next)
                minHeap.push(currentNode->next);
        }

        return dummy.next;
    }
};
