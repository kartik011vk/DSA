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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0 ;
        if(root == NULL){
            return 0 ; 
        } 
        if(root->val <= high && root->val >= low){
            sum = sum + root->val ; 
        }

        if(root->val > low){
            sum = sum + rangeSumBST(root->left, low, high) ;  
            
        }
        if(root->val < high){
            sum = sum + rangeSumBST(root->right, low, high) ;  
        }
        return sum ; 
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna