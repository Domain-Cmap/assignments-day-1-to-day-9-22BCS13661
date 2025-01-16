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
    vector<int> nodes = {1, 2, 3, NULL, 4, NULL, 5};
    TreeNode* root = buildTree(nodes);

    cout << "Constructed Binary Tree:\n";
    printTree(root);

    return 0;
}