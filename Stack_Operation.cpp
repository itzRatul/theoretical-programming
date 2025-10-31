#include <iostream>
using namespace std;

#define MAX_SIZE 5

// Global variables for stack
int stack[MAX_SIZE];
int top = -1;

// Stack functions
void push(int value) {
    if (top >= MAX_SIZE - 1) {
        cout << "Stack overflow! Cannot push " << value << endl;
        return;
    }
    stack[++top] = value;
    cout << value << " pushed to stack\n";
}

int pop() {
    if (top < 0) {
        cout << "Stack underflow! Cannot pop\n";
        return -1;
    }
    int value = stack[top--];
    cout << value << " popped from stack\n";
    return value;
}

int peek() {
    if (top < 0) {
        cout << "Stack is empty\n";
        return -1;
    }
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX_SIZE - 1;
}

void displayStackFromBottom() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements (from bottom): ";
    for (int i = 0; i <= top; i++) {  
        cout << stack[i] << " ";
    }
    cout << endl;
}

void displayStackFromTop() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements (from top): ";
    for (int i = top; i >= 0; i--) {  
        cout << stack[i] << " ";
    }
    cout << endl;
}

void showStackStatus() {
    cout << "\n--- Stack Status ---" << endl;
    cout << "Is empty: " << (isEmpty() ? "Yes" : "No") << endl;
    cout << "Is full: " << (isFull() ? "Yes" : "No") << endl;
    if (!isEmpty()) {
        cout << "Top element: " << peek() << endl;
    }
    displayStackFromBottom();
    displayStackFromTop();
    cout << "-------------------\n" << endl;
}

// Main function
int main() {
    cout << "=== STACK DEMONSTRATION ===" << endl;
    cout << "Stack Implementation using Array --> LIFO (Last In First Out)"<<endl;
    
    // Initial stack status
    showStackStatus();
    
    // Push operations
    cout << "Pushing elements..." << endl;
    push(10);
    push(20);
    push(30);
    showStackStatus();
    
    // Peek operation
    cout << "Peek operation: " << peek() << endl;
    
    // Pop operation
    cout << "Popping element..." << endl;
    pop();
    showStackStatus();
    
    // More push operations
    cout << "Pushing more elements..." << endl;
    push(40);
    push(50);
    push(60);
    showStackStatus();
    
    // Try to push when stack is full
    cout << "Trying to push when stack is full..." << endl;
    push(70); // This will show stack overflow
    
    // Multiple pop operations
    cout << "Popping all elements..." << endl;
    while (!isEmpty()) {
        pop();
    }
    showStackStatus();
    
    // Try to pop from empty stack
    cout << "Trying to pop from empty stack..." << endl;
    pop();
    
    return 0;
}