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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLen(headA);
        int lenB = getLen(headB);
        if(lenA > lenB)
        {
            int diff = lenA - lenB;
            headA = move(headA, diff);
        }
        else if(lenA < lenB)
        {
            int diff = lenB - lenA;
            headB = move(headB, diff);
        }

        while(headA && headB)
        {
            if(headA == headB)
                return headA;

            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }

    int getLen(ListNode *head) {
        ListNode* temp = head;
        int counts = 0;
        while(temp)
        {
            counts++;
            temp = temp->next;
        }

        return counts;
    }

    ListNode* move(ListNode *node, int moveCount) {
        while(moveCount-- && node)
        {
            node = node->next;
        }
        return node;
    }
};

int main()
{
    ListNode* nodeA1 = new ListNode(4);
    ListNode* nodeA2 = new ListNode(1);
    ListNode* nodeC1 = new ListNode(8);
    ListNode* nodeC2 = new ListNode(4);
    ListNode* nodeC3 = new ListNode(5);
    ListNode* headA = nodeA1;

    nodeA1->next = nodeA2;
    nodeA2->next = nodeC1;
    nodeC1->next = nodeC2;
    nodeC2->next = nodeC3;
    nodeC3->next = NULL;

    ListNode* nodeB1 = new ListNode(5);
    ListNode* nodeB2 = new ListNode(0);
    ListNode* nodeB3 = new ListNode(1);
    ListNode* headB = nodeB1;
    nodeB1->next = nodeB2;
    nodeB2->next = nodeB3;
    nodeB3->next = nodeC1;

    Solution sol;
    ListNode* intersectVal = sol.getIntersectionNode(headA, headB);
    if(intersectVal)
        cout << "intersectVal = " << intersectVal->val << endl;
    else
        cout << "No intersectVal" << endl;

    return 0;
}
