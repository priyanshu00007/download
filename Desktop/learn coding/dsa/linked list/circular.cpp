#include <iostream>

// Node structure for a singly circular linked list
struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* last; // A pointer to the last node

public:
    CircularLinkedList() {
        last = nullptr;
    }

    // Function to check if the list is empty
    bool isEmpty() {
        return last == nullptr;
    }

    // Insert a node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (isEmpty()) {
            last = newNode;
            newNode->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
        std::cout << value << " inserted at the beginning." << std::endl;
    }

    // Insert a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (isEmpty()) {
            last = newNode;
            newNode->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
        std::cout << value << " inserted at the end." << std::endl;
    }

    // Delete a node with a specific value
    void deleteNode(int key) {
        if (isEmpty()) {
            std::cout << "List is empty. Cannot delete." << std::endl;
            return;
        }

        Node* current = last->next; // Start from the first node
        Node* prev = last;

        do {
            if (current->data == key) {
                // Node to be deleted is the only node
                if (current == last->next && current == last) {
                    delete current;
                    last = nullptr;
                    std::cout << key << " deleted. List is now empty." << std::endl;
                    return;
                }
                // Node to be deleted is the first node
                if (current == last->next) {
                    prev->next = current->next;
                    delete current;
                    std::cout << key << " deleted from the beginning." << std::endl;
                    return;
                }
                // Node to be deleted is the last node
                if (current == last) {
                    prev->next = last->next;
                    delete last;
                    last = prev;
                    std::cout << key << " deleted from the end." << std::endl;
                    return;
                }
                // Node is in the middle
                prev->next = current->next;
                delete current;
                std::cout << key << " deleted." << std::endl;
                return;
            }
            prev = current;
            current = current->next;
        } while (current != last->next);

        std::cout << "Node with value " << key << " not found." << std::endl;
    }

    // Display all nodes in the list
    void display() {
        if (isEmpty()) {
            std::cout << "The list is empty." << std::endl;
            return;
        }
        
        Node* current = last->next;
        std::cout << "List: ";
        do {
            std::cout << current->data << " -> ";
            current = current->next;
        } while (current != last->next);
        std::cout << "back to start" << std::endl;
    }
};

// Main function to test the Circular Linked List
int main() {
    CircularLinkedList list;
    int choice, value;

    do {
        std::cout << "\n--- Circular Linked List Operations ---" << std::endl;
        std::cout << "1. Insert at Beginning" << std::endl;
        std::cout << "2. Insert at End" << std::endl;
        std::cout << "3. Delete a Node" << std::endl;
        std::cout << "4. Display List" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                std::cout << "Enter value to delete: ";
                std::cin >> value;
                list.deleteNode(value);
                break;
            case 4:
                list.display();
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