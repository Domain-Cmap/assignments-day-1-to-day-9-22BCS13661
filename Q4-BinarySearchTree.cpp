#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* sortedArrayToBST(const vector<int>& nums, int start, int end) {
    if (start > end) return nullptr;

    int mid = start + (end - start) / 2; // To avoid overflow
    TreeNode* root = new TreeNode(nums[mid]);

    root->left = sortedArrayToBST(nums, start, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, end);

    return root;
}

TreeNode* sortedArrayToBST(const vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size() - 1);
}

void printTree(TreeNode* root, int space = 0, int level = 0) {
    if (root == nullptr) return;

    space += 10; // Increase distance between levels

    printTree(root->right, space, level + 1);

    cout << endl;
    for (int i = 10; i < space; i++) cout << " ";
    cout << root->val << "\n";

    printTree(root->left, space, level + 1);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = sortedArrayToBST(nums);

    cout << "Constructed Balanced BST:\n";
    printTree(root);

    return 0;
}