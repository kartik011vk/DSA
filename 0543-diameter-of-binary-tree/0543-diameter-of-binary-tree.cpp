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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0 ; 
        height(root, diameter) ; 
        return diameter ; 

        
    }
    int height(TreeNode* root , int &diameter){
        if(root == NULL){
            return 0 ; 
        }
        int lefth = height(root->left , diameter) ; 
        int righth = height(root->right, diameter) ; 
        diameter = max(diameter , lefth + righth) ; 
        return 1 + max(lefth , righth) ; 
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna