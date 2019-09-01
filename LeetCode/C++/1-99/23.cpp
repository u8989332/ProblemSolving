#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }

        return mergeHelper(lists, 0, lists.size() - 1);
    }

    ListNode* mergeHelper(vector<ListNode*>& lists, int L, int R){
        if(L < R){
            int mid = (L + R) / 2;
            ListNode* temp = mergeTwoLists(mergeHelper(lists, L, mid), mergeHelper(lists, mid + 1, R));
            return temp;
        }

        return lists[L];
    }

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
    ListNode* nodeL1_2 = new ListNode(4);
    ListNode* nodeL1_3 = new ListNode(5);

    ListNode* nodeL2_1 = new ListNode(1);
    ListNode* nodeL2_2 = new ListNode(3);
    ListNode* nodeL2_3 = new ListNode(4);

    ListNode* nodeL3_1 = new ListNode(2);
    ListNode* nodeL3_2 = new ListNode(6);

    nodeL1_1->next = nodeL1_2;
    nodeL1_2->next = nodeL1_3;

    nodeL2_1->next = nodeL2_2;
    nodeL2_2->next = nodeL2_3;

    nodeL3_1->next = nodeL3_2;

    vector<ListNode*> lists;
    lists.push_back(nodeL1_1);
    lists.push_back(nodeL2_1);
    lists.push_back(nodeL3_1);

    Solution sol;
    ListNode* newHead = sol.mergeKLists(lists);
    traverseNode(newHead);
    return 0;
}
