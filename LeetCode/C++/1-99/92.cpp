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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int changeLen = n - m + 1;
        ListNode* preHead = NULL;
        ListNode* result = head;
        while(head && --m)
        {
            preHead = head;
            head = head->next;
        }
        ListNode* newPreTail = head;
        ListNode* newHead = NULL;
        while(head && changeLen)
        {
            ListNode* next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
            changeLen--;
        }

        newPreTail->next = head;
        if(preHead)
            preHead->next = newHead;
        else
            result = newHead;

        return result;
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
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;
    traverseNode(node1);

    Solution sol;
    ListNode* newHead = sol.reverseBetween(node1, 2, 4);
    traverseNode(newHead);

    return 0;
}
