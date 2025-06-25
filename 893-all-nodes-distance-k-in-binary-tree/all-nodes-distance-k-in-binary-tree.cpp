/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void markparent(TreeNode* root,  unordered_map<TreeNode*,TreeNode*> &parent){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();
        if(curr->left)
        {
        parent[curr->left]=curr;
        q.push(curr->left);
        }
          if(curr->right)
        {
        parent[curr->right]=curr;
        q.push(curr->right);
        }
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        markparent(root,parent);
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        int dist=0;
        visited[target]=true;
        while(!q.empty()){
            int size=q.size();
            if(dist==k){
                break;
            }
            dist++;
            for(int i=0;i<size;i++){
                TreeNode* curr1=q.front();
                q.pop();
                if(curr1->left && !visited[curr1->left]){
                    q.push(curr1->left);
                    visited[curr1->left]=true;
                }
                if(curr1->right && !visited[curr1->right]){
                    q.push(curr1->right);
                    visited[curr1->right]=true;
                }
                if(parent[curr1] && !visited[parent[curr1]]){
                    q.push(parent[curr1]);
                    visited[parent[curr1]]=true;
                }
            }

        }
        vector<int>result;
        while(!q.empty()){
            TreeNode* curr2=q.front();
            q.pop();
            result.push_back(curr2->val);
        }
        return result;
    }
};