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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* root1=new TreeNode(val);

        if(root==NULL)return root1;
        TreeNode* curr=root;
        while(true){
            if(val<curr->val){
                if(curr->left==NULL){
                    curr->left=root1;
                    break;
                }
                else{
                    curr=curr->left;
                }
            }
            else{
                if(curr->right==NULL){
                    curr->right=root1;
                    break;
                }
                else{
                    curr=curr->right;
                }
            }
        }
        return root;

    }
};