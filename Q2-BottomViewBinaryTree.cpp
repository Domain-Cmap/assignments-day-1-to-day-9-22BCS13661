#include <iostream>
#include <map>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void bottomView(TreeNode* root) {
    if (root == nullptr) return;

    std::map<int, int> bottomNodeMap; 
    std::queue<std::pair<TreeNode*, int>> q; 

    q.push({root, 0});

    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        TreeNode* node = p.first;
        int hd = p.second;

        bottomNodeMap[hd] = node->val;

        if (node->left) {
            q.push({node->left, hd - 1});
        }

        if (node->right) {
            q.push({node->right, hd + 1});
        }
    }

    for (const auto& pair : bottomNodeMap) {
        std::cout << pair.second << " ";
    }
    std::cout << std::endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    std::cout << "Bottom view of the binary tree: ";
    bottomView(root);

    return 0;
}