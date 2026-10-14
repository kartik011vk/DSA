
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == NULL) {
            return NULL;
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // No children
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // No left child
            else if (root->left == NULL) {
                TreeNode* temp = root;
                root = root->right;
                delete temp;
            }

            // No right child
            else if (root->right == NULL) {
                TreeNode* temp = root;
                root = root->left;
                delete temp;
            }

            // Two children
            else {
                TreeNode* temp = FindMin(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }

        return root;
    }

    TreeNode* FindMin(TreeNode* root) {
        if (root == NULL || root->left == NULL) {
            return root;
        }

        return FindMin(root->left);
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna