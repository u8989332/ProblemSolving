#include <iostream>

using namespace std;

/**
 * definition for singly-linked list.
 *
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode tempHead(0);
        ListNode* temp = &tempHead;

        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }

        if(l1)
             temp->next = l1;

        if(l2)
             temp->next = l2;

        return tempHead.next;
    }
};

void traverseNode(ListNode* head)
{
    cout << "Start traversal" << endl;
    while(head!=NULL)
    {
        cout << head->val << endl;
        head = head->next;
    }
    cout << "Finish traversal" << endl;
}


int main()
{
    ListNode* nodeL1_1 = new ListNode(1);
    ListNode* nodeL1_2 = new ListNode(2);
    ListNode* nodeL1_3 = new ListNode(4);
    ListNode* nodeL1_4 = new ListNode(7);

    ListNode* nodeL2_1 = new ListNode(1);
    ListNode* nodeL2_2 = new ListNode(3);
    ListNode* nodeL2_3 = new ListNode(5);

    nodeL1_1->next = nodeL1_2;
    nodeL1_2->next = nodeL1_3;
    nodeL1_3->next = nodeL1_4;

    nodeL2_1->next = nodeL2_2;
    nodeL2_2->next = nodeL2_3;

    Solution sol;
    ListNode* newHead = sol.mergeTwoLists(nodeL1_1, nodeL2_1);
    traverseNode(newHead);

    return 0;
}
