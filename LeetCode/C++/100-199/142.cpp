#include <iostream>

using namespace std;

/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* meetNode = NULL;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                meetNode = slow;
                break;
            }
        }

        if(!meetNode)
            return NULL;

        slow = head;
        while(slow != meetNode)
        {
            slow = slow->next;
            meetNode = meetNode->next;
        }

        return slow;

    }
};

int main()
{
    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;

    Solution sol;
    ListNode* startCycleNode = sol.detectCycle(node1);
    if(startCycleNode)
        cout << "Start node value = " << startCycleNode->val << endl;
    else
        cout << "No cycle" << endl;

    return 0;
}
