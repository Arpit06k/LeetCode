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

int inorder(TreeNode* root,int k) {
 vector<int>inorder;
        stack<TreeNode*>st;
        TreeNode* node=root;
        int cnt=0;
        while(true){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty())break;
                node=st.top();
                st.pop();
                cnt++;
                if(cnt==k)break;
                node=node->right;
            }
           }
           return node->val;
}
 

   int kthSmallest(TreeNode* root, int k) {
    return inorder(root,k);
   }
    
};