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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
    unsigned long long ans=0;
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        while(!q.empty()){
            unsigned long long size=q.size();
            unsigned long long mini=q.front().second;
            unsigned long long first,last;
            for(int i=0;i<size;i++){
                unsigned long long curr=q.front().second-mini;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0)first=curr;
                if(i==size-1)last=curr;
                if(node->left)q.push({node->left,curr*2+1});
                 if(node->right)q.push({node->right,curr*2+2});
            
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }

};