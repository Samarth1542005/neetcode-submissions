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
public:
    void inOrder(TreeNode* root , vector <int> &temp)
    {
        if(root==NULL) return;
        inOrder(root->left,temp);
        temp.push_back(root->val);
        inOrder(root->right,temp);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        inOrder(root,inorder);
        for(int i=0 ; i<inorder.size()-1 ; i++)
        {
            if(inorder[i] >= inorder[i+1])
            {
                return false;
            }
        }
        return true;
    }
};
