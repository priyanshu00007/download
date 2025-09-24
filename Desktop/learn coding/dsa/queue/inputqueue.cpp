// #include <iostream>

// // Node structure for the linked list
// struct Node {
//     int data;
//     Node* next;
// };

// class Queue {
// private:
//     Node* front;
//     Node* rear;

// public:
//     Queue() {
//         front = nullptr;
//         rear = nullptr;
//     }

//     // Operation to check if the queue is empty
//     bool isEmpty() {
//         return front == nullptr;
//     }

//     // Enqueue: Adds an element to the rear of the queue
//     void enqueue(int value) {
//         Node* newNode = new Node();
//         newNode->data = value;
//         newNode->next = nullptr;
        
//         if (isEmpty()) {
//             front = rear = newNode;
//             return;
//         }
//         rear->next = newNode;
//         rear = newNode;
//         std::cout << value << " enqueued to the queue." << std::endl;
//     }

//     // Dequeue: Removes an element from the front of the queue
//     void dequeue() {
//         if (isEmpty()) {
//             std::cout << "Queue is empty. Cannot dequeue." << std::endl;
//             return;
//         }
//         Node* temp = front;
//         int dequeuedValue = temp->data;
//         front = front->next;
//         if (front == nullptr) {
//             rear = nullptr;
//         }
//         delete temp;
//         std::cout << dequeuedValue << " dequeued from the queue." << std::endl;
//     }

//     // Display: Prints all elements in the queue from front to rear
//     void display() {
//         if (isEmpty()) {
//             std::cout << "Queue is empty." << std::endl;
//             return;
//         }
//         Node* current = front;
//         std::cout << "Queue elements: ";
//         while (current != nullptr) {
//             std::cout << current->data << " -> ";
//             current = current->next;
//         }
//         std::cout << "end" << std::endl;
//     }
// };

// int main() {
//     Queue myQueue;
//     int choice, value;

//     do {
//         std::cout << "\n--- Queue Operations ---" << std::endl;
//         std::cout << "1. Enqueue" << std::endl;
//         std::cout << "2. Dequeue" << std::endl;
//         std::cout << "3. Display" << std::endl;
//         std::cout << "4. Exit" << std::endl;
//         std::cout << "Enter your choice: ";
//         std::cin >> choice;

//         switch (choice) {
//             case 1:
//                 std::cout << "Enter value to enqueue: ";
//                 std::cin >> value;
//                 myQueue.enqueue(value);
//                 break;
//             case 2:
//                 myQueue.dequeue();
//                 break;
//             case 3:
//                 myQueue.display();
//                 break;
//             case 4:
//                 std::cout << "Exiting program." << std::endl;
//                 break;
//             default:
//                 std::cout << "Invalid choice. Please try again." << std::endl;
//                 break;
//         }
//     } while (choice != 4);

//     return 0;
// }
#include <iostream>

#define MAX_SIZE 10

class SimpleQueue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    SimpleQueue() {
        front = -1;
        rear = -1;
    }

    // Checks if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Checks if the queue is full
    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    // Adds an element to the end of the queue (enqueue)
    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue." << std::endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        arr[rear] = value;
        std::cout << value << " enqueued to the queue." << std::endl;
    }

    // Removes an element from the front of the queue (dequeue)
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }
        std::cout << arr[front] << " dequeued from the queue." << std::endl;
        if (front == rear) { // If it was the last element
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }

    // Returns the front element without removing it
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Returning -1." << std::endl;
            return -1;
        }
        return arr[front];
    }

    // Displays all elements in the queue
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        std::cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    SimpleQueue q;
    int choice, value;

    do {
        std::cout << "\n--- Queue Operations ---" << std::endl;
        std::cout << "1. Enqueue" << std::endl;
        std::cout << "2. Dequeue" << std::endl;
        std::cout << "3. Peek" << std::endl;
        std::cout << "4. Display" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to enqueue: ";
                std::cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                std::cout << "Front element is: " << q.peek() << std::endl;
                break;
            case 4:
                q.display();
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