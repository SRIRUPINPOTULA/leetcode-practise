// 988. Smallest String Starting From Leaf

// You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

// Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

// As a reminder, any shorter prefix of a string is lexicographically smaller.

// For example, "ab" is lexicographically smaller than "aba".
// A leaf of a node is a node that has no children.

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
class Solution {
private:
    string res = "";

public:
    void help(TreeNode* root, string curr, int length)
    {
        if(root->left == NULL && root->right == NULL)
        {
            if(length >= 1)
            {
                curr += root->val + 'a';
                string newStr = curr;
                reverse(newStr.begin(), newStr.end());
                // cout << newStr << endl;
                if(res == "")
                {
                    res = newStr;
                }
                else if(res != "" && newStr < res )
                {
                    res = newStr;
                }
            }
            return;
        }
        curr += root->val + 'a';
        if(root->left != NULL)
            help(root->left, curr, length+1);
        if(root->right != NULL)
            help(root->right, curr, length+1);
    }

    string smallestFromLeaf(TreeNode* root) {
        string curr = "";
        if(root == NULL)
            return "";
        else if(root != NULL && root->left == NULL && root->right == NULL)
        {
            curr += root->val + 'a';
            return curr;
        }
        help(root, curr, 0);
        return res;
    }
};