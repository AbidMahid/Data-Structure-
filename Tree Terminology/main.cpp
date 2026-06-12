#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

class Tree {
public:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* insert(Node* root, int val) {
        if (root == nullptr) {
            return new Node(val);
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr->left == nullptr) {
                curr->left = new Node(val);
                return root;
            } else {
                q.push(curr->left);
            }

            if (curr->right == nullptr) {
                curr->right = new Node(val);
                return root;
            } else {
                q.push(curr->right);
            }
        }
        return root;
    }

    int height(Node* node) {
        if (node == nullptr) return -1;
        return max(height(node->left), height(node->right)) + 1;
    }

    int depth(Node* root, Node* target, int d = 0) {
        if (root == nullptr) return -1;
        if (root == target) return d;

        int leftDepth = depth(root->left, target, d + 1);
        if (leftDepth != -1) return leftDepth;

        return depth(root->right, target, d + 1);
    }

    int countNodes(Node* root) {
        if (root == nullptr) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int countLeaves(Node* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return 1;
        return countLeaves(root->left) + countLeaves(root->right);
    }

    bool isBinary(Node* root) {
        if (root == nullptr) return true;

        int children = 0;
        if (root->left != nullptr) children++;
        if (root->right != nullptr) children++;

        if (children > 2) return false;

        return isBinary(root->left) && isBinary(root->right);
    }

    void show(Node* root) {
        cout << "\n=== Tree Info ===\n";
        cout << "Total nodes: " << countNodes(root) << endl;
        cout << "Leaf nodes: " << countLeaves(root) << endl;
        cout << "Height: " << height(root) << endl;
        cout << "Is Binary? " << (isBinary(root) ? "Yes" : "No") << endl;

        if (root) {
            cout << "Root: " << root->data << endl;
            if (root->left) cout << "Left child: " << root->left->data << endl;
            if (root->right) cout << "Right child: " << root->right->data << endl;
        }
    }

    void inorder(Node* root) {
        if (root == nullptr) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main() {
    Tree t;
    Tree::Node* root = nullptr;
    int n, val;

    cout << "How many nodes? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i+1 << ": ";
        cin >> val;
        if (root == nullptr) {
            root = new Tree::Node(val);
        } else {
            root = t.insert(root, val);
        }
    }

    cout << "\nInorder traversal: ";
    t.inorder(root);
    cout << endl;

    t.show(root);

    return 0;
}
