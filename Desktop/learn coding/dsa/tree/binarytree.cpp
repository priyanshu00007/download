#include <iostream>
#include <queue> // Needed for level-order insertion

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

class BinaryTree {
private:
    Node* root;

    // Helper function for recursive inorder traversal
    void inorderTraversal(Node* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    // Helper function for recursive preorder traversal
    void preorderTraversal(Node* node) {
        if (node != nullptr) {
            std::cout << node->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    // Helper function for recursive postorder traversal
    void postorderTraversal(Node* node) {
        if (node != nullptr) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            std::cout << node->data << " ";
        }
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    // Inserts a node in level-order
    void insert(int value) {
        Node* newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->left == nullptr) {
                current->left = newNode;
                return;
            } else {
                q.push(current->left);
            }

            if (current->right == nullptr) {
                current->right = newNode;
                return;
            } else {
                q.push(current->right);
            }
        }
    }

    // Public method for inorder traversal
    void inorder() {
        inorderTraversal(root);
        std::cout << std::endl;
    }

    // Public method for preorder traversal
    void preorder() {
        preorderTraversal(root);
        std::cout << std::endl;
    }

    // Public method for postorder traversal
    void postorder() {
        postorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BinaryTree bt;
    int choice, value;

    do {
        std::cout << "\n--- Binary Tree Operations ---" << std::endl;
        std::cout << "1. Insert a value" << std::endl;
        std::cout << "2. In-order Traversal" << std::endl;
        std::cout << "3. Pre-order Traversal" << std::endl;
        std::cout << "4. Post-order Traversal" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                bt.insert(value);
                break;
            case 2:
                std::cout << "In-order traversal: ";
                bt.inorder();
                break;
            case 3:
                std::cout << "Pre-order traversal: ";
                bt.preorder();
                break;
            case 4:
                std::cout << "Post-order traversal: ";
                bt.postorder();
                break;
            case 5:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 5);

    return 0;
}