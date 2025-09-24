#include <iostream>
#include <stack>
#include <string>

// A helper function to display the stack contents
void displayStack(std::stack<int> s) {
    if (s.empty()) {
        std::cout << "Stack is empty." << std::endl;
        return;
    }
    std::cout << "Stack contents (top to bottom): ";
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::stack<int> myStack;
    int choice;
    int value;

    do {
        std::cout << "\n--- Stack Operations (using std::stack) ---" << std::endl;
        std::cout << "1. Push (add element)" << std::endl;
        std::cout << "2. Pop (remove element)" << std::endl;
        std::cout << "3. Peek (view top element)" << std::endl;
        std::cout << "4. Display all elements" << std::endl;
        std::cout << "5. Check if stack is empty" << std::endl;
        std::cout << "6. Get stack size" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to push: ";
                std::cin >> value;
                myStack.push(value);
                std::cout << value << " pushed onto the stack." << std::endl;
                break;
            case 2:
                if (!myStack.empty()) {
                    std::cout << myStack.top() << " popped from the stack." << std::endl;
                    myStack.pop();
                } else {
                    std::cout << "Stack is empty. Cannot pop." << std::endl;
                }
                break;
            case 3:
                if (!myStack.empty()) {
                    std::cout << "Top element is: " << myStack.top() << std::endl;
                } else {
                    std::cout << "Stack is empty. No top element to display." << std::endl;
                }
                break;
            case 4:
                displayStack(myStack);
                break;
            case 5:
                if (myStack.empty()) {
                    std::cout << "The stack is empty." << std::endl;
                } else {
                    std::cout << "The stack is not empty." << std::endl;
                }
                break;
            case 6:
                std::cout << "The current size of the stack is: " << myStack.size() << std::endl;
                break;
            case 7:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 7);

    return 0;
}
// #include <iostream>
// #include <stack> // This is the library you need for std::stack

// int main() {
//     // Create a stack of integers
//     std::stack<int> s;

//     // 1. Push: Add elements to the stack
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     std::cout << "Pushed 10, 20, 30 onto the stack." << std::endl;

//     // 2. Peek (top): Access the top element
//     if (!s.empty()) {
//         std::cout << "Top element is: " << s.top() << std::endl;
//     }

//     // 3. Pop: Remove the top element
//     if (!s.empty()) {
//         std::cout << "Popping the top element (" << s.top() << ")." << std::endl;
//         s.pop();
//     }

//     // 4. Check size
//     std::cout << "Current stack size: " << s.size() << std::endl;

//     // 5. Check if empty
//     if (!s.empty()) {
//         std::cout << "The stack is not empty." << std::endl;
//     }

//     // Pop the rest of the elements
//     while (!s.empty()) {
//         std::cout << "Popping: " << s.top() << std::endl;
//         s.pop();
//     }

//     if (s.empty()) {
//         std::cout << "The stack is now empty." << std::endl;
//     }

//     return 0;
// }

// #include <iostream>

// #define MAX_SIZE 10 // Maximum size of the stack

// class SimpleStack {
// private:
//     int arr[MAX_SIZE];
//     int top;

// public:
//     // Constructor to initialize the stack
//     SimpleStack() {
//         top = -1;
//     }

//     // Checks if the stack is empty
//     bool isEmpty() {
//         return top < 0;
//     }

//     // Checks if the stack is full
//     bool isFull() {
//         return top >= (MAX_SIZE - 1);
//     }

//     // Pushes an element onto the top of the stack
//     void push(int value) {
//         if (isFull()) {
//             std::cout << "Stack Overflow: Cannot push, stack is full." << std::endl;
//             return;
//         }
//         arr[++top] = value;
//         std::cout << value << " pushed onto the stack." << std::endl;
//     }

//     // Removes an element from the top of the stack
//     void pop() {
//         if (isEmpty()) {
//             std::cout << "Stack Underflow: Cannot pop, stack is empty." << std::endl;
//             return;
//         }
//         std::cout << arr[top--] << " popped from the stack." << std::endl;
//     }

//     // Returns the top element without removing it
//     int peek() {
//         if (isEmpty()) {
//             return -1;
//         }
//         return arr[top];
//     }

//     // Displays all elements in the stack
//     void display() {
//         if (isEmpty()) {
//             std::cout << "Stack is empty." << std::endl;
//             return;
//         }
//         std::cout << "Stack elements (top to bottom): ";
//         for (int i = top; i >= 0; i--) {
//             std::cout << arr[i] << " ";
//         }
//         std::cout << std::endl;
//     }
// };

// int main() {
//     SimpleStack s;
//     int choice, value;

//     do {
//         std::cout << "\n--- Stack Operations ---" << std::endl;
//         std::cout << "1. Push" << std::endl;
//         std::cout << "2. Pop" << std::endl;
//         std::cout << "3. Peek" << std::endl;
//         std::cout << "4. Display" << std::endl;
//         std::cout << "5. Exit" << std::endl;
//         std::cout << "Enter your choice: ";
//         std::cin >> choice;

//         switch (choice) {
//             case 1:
//                 std::cout << "Enter value to push: ";
//                 std::cin >> value;
//                 s.push(value);
//                 break;
//             case 2:
//                 s.pop();
//                 break;
//             case 3:
//                 if (!s.isEmpty()) {
//                     std::cout << "Top element is: " << s.peek() << std::endl;
//                 } else {
//                     std::cout << "Stack is empty." << std::endl;
//                 }
//                 break;
//             case 4:
//                 s.display();
//                 break;
//             case 5:
//                 std::cout << "Exiting program." << std::endl;
//                 break;
//             default:
//                 std::cout << "Invalid choice. Please try again." << std::endl;
//                 break;
//         }
//     } while (choice != 5);

//     return 0;
// }