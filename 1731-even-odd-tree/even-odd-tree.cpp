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
    bool isEvenOddTree(TreeNode* root) {
        int level_no = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                level.push_back(curr->val);
                if(curr->left != nullptr){
                    q.push(curr->left);
                }
                if(curr->right != nullptr){
                    q.push(curr->right);
                }
            }
            if(level_no % 2 == 0){  // level is even
                for(int i = 0; i < level.size(); i++){
                    if(level[i] % 2 == 0){
                        return false;
                    }
                }
                for(int i = 0; i < level.size()-1; i++){
                    if(level[i] >= level[i+1]){
                        return false;
                    }
                }
            }
            else{     // level is odd
                for(int i = 0; i < level.size(); i++){
                    if(level[i] % 2 != 0){
                        return false;
                    }
                }
                for(int i = 0; i < level.size()-1; i++){
                    if(level[i] <= level[i+1]){
                        return false;
                    }
                }
            }
            level_no++;
        }
        return true;
    }
};