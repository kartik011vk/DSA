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
    bool isValidBST(TreeNode* root) {
        return Validator(root, LONG_MAX, LONG_MIN); 
    }
    bool Validator(TreeNode* root, long max_val, long min_val){
        if(root== NULL){
            return true ; 
        }
        if(root->val <= min_val || root->val >= max_val ){
            return false ; 
        }
        return Validator(root->left, root->val, min_val) && Validator(root->right,max_val, root->val ) ; 
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna