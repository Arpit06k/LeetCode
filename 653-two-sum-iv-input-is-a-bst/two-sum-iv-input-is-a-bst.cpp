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


class BSTiterator{
  stack<TreeNode*>st;
    bool reverse;
    void pushall(TreeNode* node){
        while(node!=NULL){
            st.push(node);
            if(reverse) node=node->right;
            else node=node->left;
        }
}
   public: 
    BSTiterator(TreeNode* root,bool isreverse) {
        reverse=isreverse;
        pushall(root);
    }
    
    int next() {
        TreeNode* curr=st.top();
        st.pop();
        if(!reverse) pushall(curr->right);
        else pushall(curr->left);
        return curr->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
class Solution{
public:
    
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)return false;
        BSTiterator l(root,false);
        BSTiterator r(root,true);
          int i=l.next();
          int j=r.next();
          while(i<j){
            if(i+j==k)return true;
            else if(i+j<k)i=l.next();
            else j=r.next();
          }
          return false;

    }
};