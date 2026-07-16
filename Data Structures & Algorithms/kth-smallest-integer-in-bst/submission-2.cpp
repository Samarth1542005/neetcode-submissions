class Solution {
public:
    void preorder(TreeNode *root, priority_queue<int, vector<int>, greater<int>> &pq)
    {
        if (root == NULL) return;

        preorder(root->left, pq);
        pq.push(root->val);
        preorder(root->right, pq);
    }

    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        preorder(root, pq);

        while (k > 1) {
            pq.pop();
            k--;
        }

        return pq.top();
    }
};