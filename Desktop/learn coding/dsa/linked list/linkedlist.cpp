#include <iostream>
// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert a new node at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        std::cout << value << " inserted at the beginning." << std::endl;
    }

    // Insert a new node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            std::cout << value << " inserted at the end." << std::endl;
            return;
        }

        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newNode;
        std::cout << value << " inserted at the end." << std::endl;
    }

    // Delete a node with a specific value
    void deleteNode(int key) {
        Node* temp = head;
        Node* prev = nullptr;

        // If head node itself holds the key
        if (temp != nullptr && temp->data == key) {
            head = temp->next;
            delete temp;
            std::cout << key << " deleted." << std::endl;
            return;
        }

        // Search for the key to be deleted
        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        // If key was not found in the list
        if (temp == nullptr) {
            std::cout << "Node with value " << key << " not found." << std::endl;
            return;
        }

        // Unlink the node from the list
        prev->next = temp->next;
        delete temp;
        std::cout << key << " deleted." << std::endl;
    }

    // Display all nodes in the list
    void display() {
        if (head == nullptr) {
            std::cout << "The list is empty." << std::endl;
            return;
        }

        Node* current = head;
        std::cout << "Linked List: ";
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    LinkedList list;
    int choice, value;

    do {
        std::cout << "\n--- Linked List Operations ---" << std::endl;
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