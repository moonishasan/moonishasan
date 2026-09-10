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
    int avgOfValInSubtree(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        int n = 1;  // no. of elements in the subtree
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                sum += curr->val;
                q.pop();
                if(curr->left != nullptr){
                    q.push(curr->left);
                    n++;
                }
                if(curr->right != nullptr){
                    q.push(curr->right);
                    n++;
                }
            }
        }
        return sum/n;
    }
    int averageOfSubtree(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr){
            return 1;
        }
        int count = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->val == avgOfValInSubtree(curr)){
                    count++;
                }
                if(curr->left != nullptr){
                    q.push(curr->left);
                }
                if(curr->right != nullptr){
                    q.push(curr->right);
                }
            }
        }
        return count;
    }
};