#include <iostream>
#include <queue> // For level-order traversal for display

enum Color { RED, BLACK };

// Node structure for a Red-Black Tree
struct Node {
    int data;
    Color color;
    Node *parent, *left, *right;

    Node(int data) {
        this->data = data;
        left = right = parent = nullptr;
        this->color = RED; // New nodes are always inserted as RED
    }
};

class RedBlackTree {
private:
    Node *root;

protected:
    void leftRotate(Node *x) {
        Node *y = x->right;
        x->right = y->left;
        if (y->left != nullptr)
            y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node *y) {
        Node *x = y->left;
        y->left = x->right;
        if (x->right != nullptr)
            x->right->parent = y;
        x->parent = y->parent;
        if (y->parent == nullptr)
            root = x;
        else if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
        x->right = y;
        y->parent = x;
    }

    void fixViolation(Node *&z) {
        Node *parent_pt = nullptr;
        Node *grand_parent_pt = nullptr;

        while ((z != root) && (z->color != BLACK) && (z->parent->color == RED)) {
            parent_pt = z->parent;
            grand_parent_pt = z->parent->parent;

            if (grand_parent_pt->left == parent_pt) {
                Node *uncle_pt = grand_parent_pt->right;

                if (uncle_pt != nullptr && uncle_pt->color == RED) {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    z = grand_parent_pt;
                } else {
                    if (z == parent_pt->right) {
                        leftRotate(parent_pt);
                        z = parent_pt;
                        parent_pt = z->parent;
                    }
                    rightRotate(grand_parent_pt);
                    std::swap(parent_pt->color, grand_parent_pt->color);
                    z = parent_pt;
                }
            } else {
                Node *uncle_pt = grand_parent_pt->left;

                if ((uncle_pt != nullptr) && (uncle_pt->color == RED)) {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    z = grand_parent_pt;
                } else {
                    if (z == parent_pt->left) {
                        rightRotate(parent_pt);
                        z = parent_pt;
                        parent_pt = z->parent;
                    }
                    leftRotate(grand_parent_pt);
                    std::swap(parent_pt->color, grand_parent_pt->color);
                    z = parent_pt;
                }
            }
        }
        root->color = BLACK;
    }

    void inorderHelper(Node *node) {
        if (node == nullptr) return;
        inorderHelper(node->left);
        std::cout << node->data << " ";
        inorderHelper(node->right);
    }

public:
    RedBlackTree() {
        root = nullptr;
    }

    void insert(const int &data) {
        Node *pt = new Node(data);
        Node *y = nullptr;
        Node *x = this->root;

        while (x != nullptr) {
            y = x;
            if (pt->data < x->data)
                x = x->left;
            else
                x = x->right;
        }

        pt->parent = y;
        if (y == nullptr)
            root = pt;
        else if (pt->data < y->data)
            y->left = pt;
        else
            y->right = pt;

        if (pt->parent == nullptr) {
            pt->color = BLACK;
            return;
        }

        if (pt->parent->parent == nullptr) {
            return;
        }

        fixViolation(pt);
    }

    void inorder() {
        inorderHelper(this->root);
        std::cout << std::endl;
    }
};

int main() {
    RedBlackTree rbt;
    int choice, value;

    do {
        std::cout << "\n--- Red-Black Tree Operations (Insertion Only) ---" << std::endl;
        std::cout << "1. Insert a value" << std::endl;
        std::cout << "2. Display Tree (In-order Traversal)" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                rbt.insert(value);
                std::cout << "Value " << value << " inserted." << std::endl;
                break;
            case 2:
                std::cout << "Current tree elements (In-order): ";
                rbt.inorder();
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