// 1019. Next Greater Node In Linked List
// https://leetcode.com/problems/next-greater-node-in-linked-list/
// Difficulty: Medium
// Topics: Linked List, Stack, Monotonic Stack, Array
//
// You are given the head of a linked list with n nodes.
// For each node in the list, find the value of the next greater node. That is,
// for each node, find the value of the first node that is next to it and has a
// strictly larger value than it.
// Return an integer array answer where answer[i] is the value of the next
// greater node of the ith node (1-indexed). If the ith node does not have a next
// greater node, set answer[i] = 0.

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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>temp;
        ListNode* curr = head;
        while(curr != NULL)
        {
            temp.push_back(curr->val);
            curr = curr->next;
        }

        int size = temp.size();
        vector<int>res(size, 0);
        stack<int>st;
        st.push(size-1);
        for(int i=size-2; i>=0; i--)
        {
            while(st.empty() != true && temp[st.top()] <= temp[i])
                st.pop();
            if(st.empty() != true)
            {
                res[i] = temp[st.top()];
            }
            st.push(i);
        }

        return res;
    }
};