#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    TreeNode* root;

    void inorderRec(TreeNode* node) {
        if (node == nullptr) return;
        inorderRec(node->left);
        cout << node->data << " ";
        inorderRec(node->right);
    }

    void preorderRec(TreeNode* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorderRec(node->left);
        preorderRec(node->right);
    }

    void postorderRec(TreeNode* node) {
        if (node == nullptr) return;
        postorderRec(node->left);
        postorderRec(node->right);
        cout << node->data << " ";
    }

    int heightRec(TreeNode* node) {
        if (node == nullptr) return -1;
        int leftHeight = heightRec(node->left);
        int rightHeight = heightRec(node->right);
        return max(leftHeight, rightHeight) + 1;
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int value) {
        if (root == nullptr) {
            root = new TreeNode(value);
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (current->left == nullptr) {
                current->left = new TreeNode(value);
                return;
            } else {
                q.push(current->left);
            }

            if (current->right == nullptr) {
                current->right = new TreeNode(value);
                return;
            } else {
                q.push(current->right);
            }
        }
    }

    void inorder() {
        cout << "Inorder traversal: ";
        inorderRec(root);
        cout << endl;
    }

    void preorder() {
        cout << "Preorder traversal: ";
        preorderRec(root);
        cout << endl;
    }

    void postorder() {
        cout << "Postorder traversal: ";
        postorderRec(root);
        cout << endl;
    }

    void levelOrder() {
        if (root == nullptr) return;

        queue<TreeNode*> q;
        q.push(root);

        cout << "Level order traversal: ";
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);
        }
        cout << endl;
    }

    int height() {
        return heightRec(root);
    }
};

int main() {
    BinaryTree tree;
    int n, value;

    cout << "How many nodes do you want to insert? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        tree.insert(value);
    }

    tree.inorder();
    tree.preorder();
    tree.postorder();
    tree.levelOrder();
    cout << "Height of tree: " << tree.height() << endl;

    return 0;
}
