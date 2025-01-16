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

void preOrder(TreeNode* root, vector<int>& result) {
    if (root) {
        result.push_back(root->val);
        preOrder(root->left, result);
        preOrder(root->right, result);
    }
}

void inOrder(TreeNode* root, vector<int>& result) {
    if (root) {
        inOrder(root->left, result);
        result.push_back(root->val);
        inOrder(root->right, result);
    }
}

void postOrder(TreeNode* root, vector<int>& result) {
    if (root) {
        postOrder(root->left, result);
        postOrder(root->right, result);
        result.push_back(root->val);
    }
}

int main() {
    vector<int> nodes = {1, 2, 3, NULL, 4, NULL, 5};
    TreeNode* root = buildTree(nodes);

    vector<int> preOrderResult;
    vector<int> inOrderResult;
    vector<int> postOrderResult;

    preOrder(root, preOrderResult);
    inOrder(root, inOrderResult);
    postOrder(root, postOrderResult);

    cout << "Pre-order: ";
    for (int val : preOrderResult) {
        cout << val << " ";
    }
    cout << endl;

    cout << "In-order: ";
    for (int val : inOrderResult) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Post-order: ";
    for (int val : postOrderResult) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}