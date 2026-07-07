// 24. Swap Nodes in Pairs

// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
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
    ListNode* swapPairs(ListNode* head) {
        int length = 0;

        if(head == NULL)
            return NULL;
        
        if(head != NULL && head->next == NULL)
            return head;
        
        ListNode* curr = head;
        while(curr != NULL)
        {
            length += 1;
            curr = curr->next;
        }
        cout << length << endl;
        curr = head;
        int swapCount = 0;
        ListNode* newHead = NULL;
        ListNode* prev = NULL;
        while(swapCount < length/2 && curr !=  NULL)
        {
            ListNode* first = curr;
            ListNode* second = curr->next;
            ListNode* third = second->next;
            if(swapCount == 0)
                newHead = second;
            second->next = first;
            first->next = third;
            if(prev != NULL)
                prev -> next = second;
            prev = first;
            curr = third;
            swapCount += 1;
        }
        return newHead;
    }
};