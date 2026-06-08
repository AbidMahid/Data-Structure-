#include <iostream>
using namespace std;

class BSTNode {
public:
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    BSTNode* root;

    BSTNode* insertRec(BSTNode* node, int value) {
        if (node == nullptr) {
            return new BSTNode(value);
        }

        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else if (value > node->data) {
            node->right = insertRec(node->right, value);
        }

        return node;
    }

    BSTNode* searchRec(BSTNode* node, int value) {
        if (node == nullptr || node->data == value) {
            return node;
        }

        if (value < node->data) {
            return searchRec(node->left, value);
        }
        return searchRec(node->right, value);
    }

    BSTNode* findMin(BSTNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    BSTNode* deleteRec(BSTNode* node, int value) {
        if (node == nullptr) return node;

        if (value < node->data) {
            node->left = deleteRec(node->left, value);
        } else if (value > node->data) {
            node->right = deleteRec(node->right, value);
        } else {
            if (node->left == nullptr) {
                BSTNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                BSTNode* temp = node->left;
                delete node;
                return temp;
            }

            BSTNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteRec(node->right, temp->data);
        }
        return node;
    }

    void inorderRec(BSTNode* node) {
        if (node != nullptr) {
            inorderRec(node->left);
            cout << node->data << " ";
            inorderRec(node->right);
        }
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRec(root, value);
        cout << value << " inserted into BST\n";
    }

    bool search(int value) {
        BSTNode* result = searchRec(root, value);
        return result != nullptr;
    }

    void deleteNode(int value) {
        root = deleteRec(root, value);
        cout << value << " deleted from BST\n";
    }

    void display() {
        cout << "BST Inorder: ";
        inorderRec(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;
    int n, value, choice;

    cout << "How many nodes do you want to insert? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        bst.insert(value);
    }

    bst.display();

    cout << "\nEnter value to search: ";
    cin >> value;
    cout << "Search " << value << ": " << (bst.search(value) ? "Found" : "Not Found") << endl;

    cout << "\nEnter value to delete: ";
    cin >> value;
    bst.deleteNode(value);
    bst.display();

    return 0;
}
