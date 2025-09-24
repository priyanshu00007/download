#include <iostream>

// Node structure for a Binary Search Tree
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

class BinarySearchTree {
private:
    Node* root;

    // Helper function to insert a new node recursively
    Node* insertNode(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }
        return node;
    }

    // Helper function to search for a value
    bool searchNode(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == value) {
            return true;
        }
        if (value < node->data) {
            return searchNode(node->left, value);
        }
        return searchNode(node->right, value);
    }

    // Traversal: In-order traversal (left, root, right)
    void inorderTraversal(Node* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    // Traversal: Pre-order traversal (root, left, right)
    void preorderTraversal(Node* node) {
        if (node != nullptr) {
            std::cout << node->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    // Traversal: Post-order traversal (left, right, root)
    void postorderTraversal(Node* node) {
        if (node != nullptr) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            std::cout << node->data << " ";
        }
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    // Public method to insert a value
    void insert(int value) {
        root = insertNode(root, value);
    }

    // Public method to search for a value
    bool search(int value) {
        return searchNode(root, value);
    }

    // Public methods for traversals
    void inorder() {
        inorderTraversal(root);
        std::cout << std::endl;
    }

    void preorder() {
        preorderTraversal(root);
        std::cout << std::endl;
    }

    void postorder() {
        postorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree bst;
    int choice, value;

    do {
        std::cout << "\n--- Binary Search Tree Operations ---" << std::endl;
        std::cout << "1. Insert a value" << std::endl;
        std::cout << "2. Search for a value" << std::endl;
        std::cout << "3. In-order Traversal" << std::endl;
        std::cout << "4. Pre-order Traversal" << std::endl;
        std::cout << "5. Post-order Traversal" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                bst.insert(value);
                break;
            case 2:
                std::cout << "Enter value to search: ";
                std::cin >> value;
                if (bst.search(value)) {
                    std::cout << "Value " << value << " found in the tree." << std::endl;
                } else {
                    std::cout << "Value " << value << " not found in the tree." << std::endl;
                }
                break;
            case 3:
                std::cout << "In-order traversal: ";
                bst.inorder();
                break;
            case 4:
                std::cout << "Pre-order traversal: ";
                bst.preorder();
                break;
            case 5:
                std::cout << "Post-order traversal: ";
                bst.postorder();
                break;
            case 6:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 6);

    return 0;
}