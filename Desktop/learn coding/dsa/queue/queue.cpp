#include <iostream>

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Operation to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Operation to add an element to the rear of the queue
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        
        if (isEmpty()) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    // Operation to remove an element from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    // Operation to view the front element without removing it
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Returning -1." << std::endl;
            return -1;
        }
        return front->data;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Front element: " << q.peek() << std::endl;

    q.dequeue();
    std::cout << "Front element after dequeue: " << q.peek() << std::endl;

    return 0;
}