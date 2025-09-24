#include <iostream>
#include <queue>

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

// Function to insert a node in a level-order fashion
Node* insert(Node* root, int value) {
    Node* newNode = new Node(value);
    if (root == nullptr) {
        return newNode;
    }

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current->left == nullptr) {
            current->left = newNode;
            return root;
        } else {
            q.push(current->left);
        }

        if (current->right == nullptr) {
            current->right = newNode;
            return root;
        } else {
            q.push(current->right);
        }
    }
    return root;
}

// Function to perform Breadth-First Search (BFS)
void bfs(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        std::cout << current->data << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
    std::cout << std::endl;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);

    std::cout << "BFS Traversal (Level by Level): ";
    bfs(root);

    return 0;
}