#include <iostream>

// Node structure for a Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// --- DFS Traversal Functions ---
// 1. Pre-order Traversal (Root, Left, Right)
void preorderTraversal(Node* node) {
    if (node != nullptr) {
        std::cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

// 2. In-order Traversal (Left, Root, Right)
void inorderTraversal(Node* node) {
    if (node != nullptr) {
        inorderTraversal(node->left);
        std::cout << node->data << " ";
        inorderTraversal(node->right);
    }
}

// 3. Post-order Traversal (Left, Right, Root)
void postorderTraversal(Node* node) {
    if (node != nullptr) {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        std::cout << node->data << " ";
    }
}

int main() {
    // Manually build a sample binary tree
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    std::cout << "Pre-order Traversal: ";
    preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "In-order Traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Post-order Traversal: ";
    postorderTraversal(root);
    std::cout << std::endl;

    return 0;
}