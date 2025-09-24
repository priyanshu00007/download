#include <iostream>

#define MAX_SIZE 10

class CircularQueue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Operation to check if the queue is full
    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    // Operation to check if the queue is empty
    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    // Operation to add an element to the rear
    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue." << std::endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = value;
    }

    // Operation to remove an element from the front
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }
        if (front == rear) { // Last element in the queue
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    // Operation to view the front element
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Returning -1." << std::endl;
            return -1;
        }
        return arr[front];
    }
};

int main() {
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Front element: " << q.peek() << std::endl;

    q.dequeue();
    std::cout << "Front element after dequeue: " << q.peek() << std::endl;

    return 0;
}