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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN ; 
        maximum_sum(root , maxi) ; 
        return maxi ; 
        
    }

    int maximum_sum(TreeNode* root, int &maxi){
        if(root == NULL){
            return 0 ; 
        }
        int leftsum = max(0 , maximum_sum(root->left, maxi)) ; 
        int rightsum = max(0, maximum_sum(root->right, maxi)) ;
        maxi = max(maxi , leftsum + rightsum + root->val) ; 
        return root->val + max(leftsum ,rightsum ) ; 
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna