#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == NULL) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    for (size_t i = 1; i < nodes.size(); i++) {
        TreeNode* current = q.front();
        q.pop();

        if (nodes[i] != NULL) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        if (++i < nodes.size() && nodes[i] != NULL) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
    }
    return root;
}

int height(TreeNode* root) {
    if (root == nullptr) {
        return 0; // Height of an empty tree is 0
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight); // Height of the current node
}

int main() {
    vector<int> nodes = {1, 2, 3, NULL, 4};
    TreeNode* root = buildTree(nodes);

    int treeHeight = height(root);
    cout << "Height of the binary tree: " << treeHeight << endl; // Output: 3

    return 0;
}