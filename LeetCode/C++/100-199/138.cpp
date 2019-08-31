#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodeMap;

        Node *temp = head;
        while(temp) {
            nodeMap[temp] = new Node(temp->val, NULL, NULL);
            temp = temp->next;
        }

        temp = head;
        while(temp) {
            nodeMap[temp]->next = nodeMap[temp->next];
            nodeMap[temp]->random = nodeMap[temp->random];
            temp=temp->next;
        }

        return nodeMap[head];
    }
};

void traverseNode(Node* head)
{
    cout << "Start traversal" << endl;
    while(head!=NULL)
    {
        cout << "Current value : " << head->val << endl;
        if(head->next)
            cout << "Next value : " << head->next->val << endl;
        else
            cout << "Next is null" << endl;

        if(head->random)
            cout << "Random value : " << head->random->val << endl;
        else
            cout << "Random is null" << endl;

        head = head->next;
    }
    cout << "Finish traversal" << endl;
}

int main()
{
    Node node1(1, NULL, NULL);
    Node node2(2, NULL, NULL);
    Node node3(3, NULL, NULL);

    node1.next = &node2;
    node2.next = &node3;

    node1.random = &node3;
    node2.random = &node1;
    node3.random = &node2;
    traverseNode(&node1);
    cout << "===========" <<endl;

    Solution sol;
    Node* newDeepCopyHead = sol.copyRandomList(&node1);
    traverseNode(newDeepCopyHead);
    return 0;
}
