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
    void preorder(TreeNode *root , vector <int> &ans)
    {
        if(root==NULL) return;
        preorder(root->left,ans);
        ans.push_back(root->val);
        preorder(root->right,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector <int> ans;
        preorder(root,ans);
        priority_queue <int , vector<int> , greater<int>> pq;
        for(int i=0 ; i<ans.size() ; i++)
        {
            pq.push(ans[i]);
        }
        while(k>1)
        {
            pq.pop();
            k--;
        }
        return pq.top();
    }
};
