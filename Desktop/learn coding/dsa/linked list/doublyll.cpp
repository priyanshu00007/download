#include <iostream>

// Node structure for a doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert a new node at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
        std::cout << value << " inserted at the beginning." << std::endl;
    }

    // Insert a new node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;
        if (head == nullptr) {
            head = newNode;
        }
        std::cout << value << " inserted at the end." << std::endl;
    }

    // Delete a node with a specific value
    void deleteNode(int key) {
        Node* current = head;

        while (current != nullptr && current->data != key) {
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Node with value " << key << " not found." << std::endl;
            return;
        }

        // Adjust previous node's next pointer
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        // Adjust next node's previous pointer
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }

        delete current;
        std::cout << key << " deleted." << std::endl;
    }

    // Display the list from head to tail
    void displayForward() {
        if (head == nullptr) {
            std::cout << "The list is empty." << std::endl;
            return;
        }
        Node* current = head;
        std::cout << "List (Forward): ";
        while (current != nullptr) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Display the list from tail to head
    void displayBackward() {
        if (tail == nullptr) {
            std::cout << "The list is empty." << std::endl;
            return;
        }
        Node* current = tail;
        std::cout << "List (Backward): ";
        while (current != nullptr) {
            std::cout << current->data << " <-> ";
            current = current->prev;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    DoublyLinkedList list;
    int choice, value;

    do {
        std::cout << "\n--- Doubly Linked List Operations ---" << std::endl;
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