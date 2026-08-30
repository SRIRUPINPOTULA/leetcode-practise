// 2487. Remove Nodes From Linked List
// https://leetcode.com/problems/remove-nodes-from-linked-list/
// Difficulty: Medium
// Topics: Linked List, Stack, Recursion, Monotonic Stack
//
// You are given the head of a linked list.
// Remove every node which has a node with a greater value anywhere to the
// right side of it.
// Return the head of the modified linked list.

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
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode*>st;
        ListNode* curr = head;
        st.push_back(curr);
        curr = curr->next;
        while(curr != NULL)
        {
            while(st.size() != 0 && st.back()->val < curr->val)
            {
                st.pop_back();
            }
            st.push_back(curr);
            curr = curr->next;
        }
        
        if(st.size() == 0)
            return NULL;
        
        ListNode* newHead = st[0];
        curr = newHead;
        for(int i=1; i<st.size(); i++)
        {
            curr->next = st[i];
            curr = curr->next;
        }
        curr->next = NULL;
        return newHead;
    }   
};