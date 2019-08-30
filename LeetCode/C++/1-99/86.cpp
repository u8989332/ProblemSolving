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
    ListNode* partition(ListNode* head, int x) {
        ListNode lessNode(0);
        ListNode greaterNode(0);
        ListNode* lessPtr = &lessNode;
        ListNode* greaterPtr = &greaterNode;
        while(head)
        {
            if(head->val < x) {
                lessPtr->next = head;
                lessPtr = lessPtr->next;
            }
            else {
                greaterPtr->next = head;
                greaterPtr = greaterPtr->next;
            }
            head = head->next;
        }
        lessPtr->next = greaterNode.next;
        greaterPtr->next = NULL;

        return lessNode.next;
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
    ListNode* node2 = new ListNode(4);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(2);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(2);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = NULL;

    Solution sol;
    ListNode* newListHead = sol.partition(node1, 3);
    traverseNode(newListHead);
    return 0;
}
