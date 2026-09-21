// 430. Flatten a Multilevel Doubly Linked List
// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
// Difficulty: Medium
// Topics: Linked List, Depth-First Search, Recursion, Stack
//
// You are given a doubly linked list, which contains nodes that have a next
// pointer, a previous pointer, and an additional child pointer. This child
// pointer may or may not point to a separate doubly linked list, also
// containing these special nodes. These child lists may have one or more
// children of their own, and so on, to produce a multilevel data structure as
// shown in the example below.
//
// Given the head of the first level of the list, flatten the list so that all
// the nodes appear in a single-level, doubly linked list. Let curr be a node
// with a child list. The nodes in the child list should appear after curr and
// before curr.next in the flattened list.
//
// Return the head of the flattened list. The nodes in the list must have all of
// their child pointers set to null.

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
private:
    vector<int>allNodes;
public:
    void help(Node* newHead)
    {
        Node* newcurr = newHead;
        while(newcurr != NULL)
        {
            allNodes.push_back(newcurr->val);
            if(newcurr->child != NULL)
            {
                help(newcurr->child);
            }
            newcurr = newcurr->next;
        }
    }

    Node* flatten(Node* head) {
        Node *curr = head;
        if(head == NULL)
            return head;
        while(curr != NULL)
        {
            allNodes.push_back(curr->val);
            if(curr->child != NULL)
            {
                help(curr->child);
            }
            curr = curr->next;
        }
        Node *newHead = new Node(head->val);
        newHead->child = NULL;
        curr = newHead;
        for(int i=1; i<allNodes.size(); i++)
        {
            Node* newNode = new Node(allNodes[i]);
            curr->next = newNode;
            newNode->prev = curr;
            newNode->child = NULL;
            curr = newNode;
        }
        return newHead;
    }
};