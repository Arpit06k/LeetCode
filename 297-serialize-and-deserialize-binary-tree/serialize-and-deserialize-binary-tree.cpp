/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)return "";
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL)s.append("#,");
            else s.append(to_string(curr->val)+',');
            if(curr!=NULL){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())return NULL;
        stringstream ss(data);
        string val;
        getline(ss,val,',');
        queue<TreeNode*>q;
        TreeNode* root=new TreeNode(stoi(val));
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();

            if(getline(ss,val,',')){
                if(val=="#"){
                    curr->left=NULL;
                }
                else{
                    TreeNode* left1=new TreeNode(stoi(val));
                    curr->left=left1;
                    q.push(left1);
                }
            }
            
            if(getline(ss,val,',')){
                if(val=="#"){
                    curr->right=NULL;
                }
                else{
                    TreeNode* right1=new TreeNode(stoi(val));
                    curr->right=right1;
                    q.push(right1);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));