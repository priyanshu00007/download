#include <iostream>
#include <algorithm> // For std::max

// Node structure for an AVL Tree
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
        height = 1; // New node is initially at height 1
    }
};

class AVLTree {
private:
    Node* root;

    // Helper function to get the height of a node
    int height(Node* N) {
        if (N == nullptr)
            return 0;
        return N->height;
    }

    // Helper function to get the balance factor of a node
    int getBalanceFactor(Node* N) {
        if (N == nullptr)
            return 0;
        return height(N->left) - height(N->right);
    }

    // Right rotation
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = 1 + std::max(height(y->left), height(y->right));
        x->height = 1 + std::max(height(x->left), height(x->right));

        return x;
    }

    // Left rotation
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = 1 + std::max(height(x->left), height(x->right));
        y->height = 1 + std::max(height(y->left), height(y->right));

        return y;
    }

    // Recursive function to insert a value and balance the tree
    Node* insert(Node* node, int value) {
        // 1. Perform standard BST insertion
        if (node == nullptr)
            return (new Node(value));

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else // Equal values are not allowed in this implementation
            return node;

        // 2. Update height of this ancestor node
        node->height = 1 + std::max(height(node->left), height(node->right));

        // 3. Get the balance factor and check for imbalance
        int balance = getBalanceFactor(node);

        // Left Left Case
        if (balance > 1 && value < node->left->data)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && value > node->right->data)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        // Return the unchanged node pointer
        return node;
    }

    // Helper function for pre-order traversal (to show tree structure)
    void preOrder(Node* node) {
        if (node != nullptr) {
            std::cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

public:
    AVLTree() {
        root = nullptr;
    }

    // Public method to insert a value
    void insert(int value) {
        root = insert(root, value);
    }

    // Public method to perform pre-order traversal
    void preOrder() {
        preOrder(root);
        std::cout << std::endl;
    }
};

int main() {
    AVLTree avl;
    int choice, value;

    do {
        std::cout << "\n--- AVL Tree Operations ---" << std::endl;
        std::cout << "1. Insert a value" << std::endl;
        std::cout << "2. Display Tree (Pre-order Traversal)" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                avl.insert(value);
                std::cout << "Value " << value << " inserted. Tree may have rebalanced." << std::endl;
                break;
            case 2:
                std::cout << "Current tree structure (Pre-order): ";
                avl.preOrder();
                break;
            case 3:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 3);

    return 0;
}