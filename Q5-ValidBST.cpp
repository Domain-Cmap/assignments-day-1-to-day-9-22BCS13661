#include <iostream>
#include <limits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isValidBSTHelper(TreeNode* node, long minVal, long maxVal) {
    if (node == nullptr) return true; // An empty tree is a valid BST

    if (node->val <= minVal || node->val >= maxVal) {
        return false; // Current node's value is out of the valid range
    }

    // Recursively check the left and right subtrees
    return isValidBSTHelper(node->left, minVal, node->val) &&
           isValidBSTHelper(node->right, node->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, numeric_limits<long>::min(), numeric_limits<long>::max());
}

int main() {
    // Example 1: Valid BST
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);

    cout << "Is the first tree a valid BST? " << (isValidBST(root1) ? "True" : "False") << endl; // Output: True

    // Example 2: Invalid BST
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);

    cout << "Is the second tree a valid BST? " << (isValidBST(root2) ? "True" : "False") << endl; // Output: False

    // Clean up memory (not shown for brevity)
    return 0;
}