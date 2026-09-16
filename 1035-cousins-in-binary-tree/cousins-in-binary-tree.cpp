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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        int levelIdx = 0;
        int level_x;
        int level_y;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->val == x){
                    level_x = levelIdx;
                }
                else if(curr->val == y){
                    level_y = levelIdx;
                }

                if(curr->left != nullptr && curr->right != nullptr && 
                    ((curr->left->val == x && curr->right->val == y) || 
                    (curr->left->val == y && curr->right->val == x))){
                    return false;
                }
                if(curr->left != nullptr){
                    q.push(curr->left);
                }
                if(curr->right != nullptr){
                    q.push(curr->right);
                }
            }  
            levelIdx++;
        } 
        if(level_x != level_y){
            return false;
        }
        return true;
    }
};