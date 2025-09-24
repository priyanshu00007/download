#include <iostream>

// Node structure for a doubly circular linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyCircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyCircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Function to check if the list is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Insert a node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (isEmpty()) {
            head = newNode;
            tail = newNode;
            newNode->next = head;
            newNode->prev = tail;
        } else {
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode;
        }
        std::cout << value << " inserted at the beginning." << std::endl;
    }

    // Insert a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (isEmpty()) {
            head = newNode;
            tail = newNode;
            newNode->next = head;
            newNode->prev = tail;
        } else {
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            tail = newNode;
        }
        std::cout << value << " inserted at the end." << std::endl;
    }

    // Delete a node with a specific value
    void deleteNode(int key) {
        if (isEmpty()) {
            std::cout << "List is empty. Cannot delete." << std::endl;
            return;
        }

        Node* current = head;
        // Search for the node to delete
        while (current->data != key) {
            current = current->next;
            if (current == head) { // We've looped back without finding the key
                std::cout << "Node with value " << key << " not found." << std::endl;
                return;
            }
        }
        
        // Handle the case of a single node in the list
        if (current->next == head && current->prev == tail) {
            head = nullptr;
            tail = nullptr;
            delete current;
            std::cout << key << " deleted. List is now empty." << std::endl;
            return;
        }
        
        current->prev->next = current->next;
        current->next->prev = current->prev;

        // Update head or tail if the deleted node was one of them
        if (current == head) {
            head = current->next;
        }
        if (current == tail) {
            tail = current->prev;
        }

        delete current;
        std::cout << key << " deleted." << std::endl;
    }

    // Display the list in the forward direction
    void displayForward() {
        if (isEmpty()) {
            std::cout << "The list is empty." << std::endl;
            return;
        }
        Node* current = head;
        std::cout << "List (Forward): ";
        do {
            std::cout << current->data << " <-> ";
            current = current->next;
        } while (current != head);
        std::cout << "head" << std::endl;
    }

    // Display the list in the backward direction
    void displayBackward() {
        if (isEmpty()) {
            std::cout << "The list is empty." << std::endl;
            return;
        }
        Node* current = tail;
        std::cout << "List (Backward): ";
        do {
            std::cout << current->data << " <-> ";
            current = current->prev;
        } while (current != tail);
        std::cout << "tail" << std::endl;
    }
};

// Main function for user interaction
int main() {
    DoublyCircularLinkedList list;
    int choice, value;

    do {
        std::cout << "\n--- Doubly Circular Linked List Operations ---" << std::endl;
        std::cout << "1. Insert at Beginning" << std::endl;
        std::cout << "2. Insert at End" << std::endl;
        std::cout << "3. Delete a Node" << std::endl;
        std::cout << "4. Display Forward" << std::endl;
        std::cout << "5. Display Backward" << std::endl;
        std::cout << "6. Exit" << std::endl;
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
                list.displayForward();
                break;
            case 5:
                list.displayBackward();
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