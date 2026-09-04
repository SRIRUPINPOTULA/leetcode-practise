// 173. Binary Search Tree Iterator
// https://leetcode.com/problems/binary-search-tree-iterator/
// Difficulty: Medium
// Topics: Stack, Tree, Design, Binary Search Tree, Binary Tree, Iterator
//
// Implement the BSTIterator class that represents an iterator over the in-order
// traversal of a binary search tree (BST):
//   BSTIterator(TreeNode root) Initializes an object of the BSTIterator class.
//     The root of the BST is given as part of the constructor. The pointer
//     should be initialized to a non-existent number smaller than any element
//     in the BST.
//   boolean hasNext() Returns true if there exists a number in the traversal to
//     the right of the pointer, otherwise returns false.
//   int next() Moves the pointer to the right, then returns the number at the
//     pointer.
//
// Notice that by initializing the pointer to a non-existent smallest number, the
// first call to next() will return the smallest element in the BST.
// You may assume that next() calls will always be valid. That is, there will be
// at least a next number in the in-order traversal when next() is called.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    vector<TreeNode*>inorder;
    TreeNode *curr = NULL;
    int iteration = 0;
    unordered_map<TreeNode*, int>mp;
    void inorderTraversal(TreeNode* currNode)
    {
        if(currNode == NULL)
            return;
        inorderTraversal(currNode->left);
        inorder.push_back(currNode);
        inorderTraversal(currNode->right);
    }

public:
    
    BSTIterator(TreeNode* root) {
        inorderTraversal(root);
        int smallestElement = inorder[0]->val;
        curr = new TreeNode(smallestElement - 1);
        for(int i=0; i<inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
    }
    
    int next() {
        if(iteration == 0)
        {
            curr = inorder[0];
        }
        else
        {
            int index = mp[curr];
            curr = inorder[index+1];
        }
        iteration++;
        return curr->val;
    }
    
    bool hasNext() {
        if(iteration == 0 && inorder.size() == 0)
            return false;
        if(iteration == 0 && inorder.size() != 0)
        {
            return true;
        }
        else
        {
            int index = mp[curr];
            if(index + 1 < inorder.size())
                return true;
        }
        return false;   
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */