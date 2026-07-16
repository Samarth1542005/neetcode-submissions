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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int qSize = q.size();
            vector<int> temp;
            for(int i=0 ; i<qSize ; i++)
            {
                auto first = q.front();
                q.pop();

                temp.push_back(first->val);
                if(first->left) q.push(first->left);
                if(first->right) q.push(first->right);
            }
            int n = temp.size();
            ans.push_back(temp[n-1]);
        }
        return ans;
    }
};
