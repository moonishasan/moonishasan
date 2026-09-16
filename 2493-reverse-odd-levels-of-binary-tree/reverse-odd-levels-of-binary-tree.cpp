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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr){
            return root;
        }
        int levelIdx = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<TreeNode*> level;
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left != nullptr){
                    q.push(curr->left);
                    level.push_back(curr->left);
                }
                if(curr->right != nullptr){
                    q.push(curr->right);
                    level.push_back(curr->right);
                }
            }
            levelIdx++;
            if(levelIdx % 2 != 0){
                int i = 0;
                int j = level.size()-1;
                while(i < j){
                    swap(level[i]->val, level[j]->val);
                    i++;
                    j--;
                }
            }            
        }
        return root;
    }
};