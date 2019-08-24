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
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL;
        while(head!=NULL)
        {
            ListNode* next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
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
    ListNode* newHead = sol.reverseList(node1);
    traverseNode(newHead);

    return 0;
}
