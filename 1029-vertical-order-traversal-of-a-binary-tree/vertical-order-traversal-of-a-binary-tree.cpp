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
     map<int, map<int, multiset<int>>> mpp;

    void preorder(TreeNode* node, int x, int y) {
        if (!node) return;

        // Process current node first (preorder)
        mpp[x][y].insert(node->val);

        // Traverse left subtree
        preorder(node->left, x - 1, y + 1);

        // Traverse right subtree
        preorder(node->right, x + 1, y + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        preorder(root, 0, 0);  // root at position (0, 0)

        vector<vector<int>> ans;
        for (auto& col : mpp) {
            vector<int> level;
            for (auto& row : col.second) {
                level.insert(level.end(), row.second.begin(), row.second.end());
            }
            ans.push_back(level);
        }
        return ans;
    }
};