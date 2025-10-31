#include <iostream>
using namespace std;

#define MAX_SIZE 5

// Global variables for queue
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Queue functions
bool isEmpty() {
    return front == -1 && rear == -1;
}

bool isFull() {
    return rear == MAX_SIZE - 1;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue overflow! Cannot enqueue " << value << endl;
        return;
    }
    
    if (isEmpty()) {
        // First element being added
        front = rear = 0;
    } else {
        rear++;
    }
    
    queue[rear] = value;
    cout << value << " enqueued to queue\n";
}

int dequeue() {
    if (isEmpty()) {
        cout << "Queue underflow! Cannot dequeue\n";
        return -1;
    }
    
    int value = queue[front];
    cout << value << " dequeued from queue\n";
    
    if (front == rear) {
        // Queue becomes empty after this dequeue
        front = rear = -1;
    } else {
        front++;
    }
    
    return value;
}

int peek() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return -1;
    }
    return queue[front];
}

int getRear() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return -1;
    }
    return queue[rear];
}

void displayQueue() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return;
    }
    
    cout << "Queue elements (front to rear): ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

void showQueueStatus() {
    cout << "\n--- Queue Status ---" << endl;
    cout << "Is empty: " << (isEmpty() ? "Yes" : "No") << endl;
    cout << "Is full: " << (isFull() ? "Yes" : "No") << endl;
    if (!isEmpty()) {
        cout << "Front element: " << peek() << endl;
        cout << "Rear element: " << getRear() << endl;
    }
    cout << "Front index: " << front << endl;
    cout << "Rear index: " << rear << endl;
    displayQueue();
    cout << "-------------------\n" << endl;
}

// Visual representation of queue
void visualizeQueue() {
    cout << "\nQueue Visualization:" << endl;
    cout << "Indices:  ";
    for (int i = 0; i < MAX_SIZE; i++) {
        cout << i << "     ";
    }
    cout << endl;
    
    cout << "Elements: ";
    for (int i = 0; i < MAX_SIZE; i++) {
        if (i >= front && i <= rear && !isEmpty()) {
            cout << queue[i];
        } else {
            cout << "X";
        }
        cout << "     ";
    }
    cout << endl;
    
    cout << "Pointers: ";
    for (int i = 0; i < MAX_SIZE; i++) {
        if (i == front && i == rear && !isEmpty()) {
            cout << "F,R";
        } else if (i == front && !isEmpty()) {
            cout << "F";
        } else if (i == rear && !isEmpty()) {
            cout << "R";
        } else {
            cout << " ";
        }
        cout << "    ";
    }
    cout << endl;
}

// Main function
int main() {
    cout << "=== QUEUE DEMONSTRATION ===" << endl;
    cout << "Queue Implementation using Array --> FIFO (First In First Out)" << endl;
    
    // Initial queue status
    showQueueStatus();
    visualizeQueue();
    
    // Enqueue operations
    cout << "PHASE 1: Enqueue operations..." << endl;
    enqueue(10);
    enqueue(20);
    enqueue(30);
    showQueueStatus();
    visualizeQueue();
    
    // Dequeue operation
    cout << "PHASE 2: Dequeue operation..." << endl;
    dequeue();
    showQueueStatus();
    visualizeQueue();
    
    // More enqueue operations
    cout << "PHASE 3: More enqueue operations..." << endl;
    enqueue(40);
    enqueue(50);
    enqueue(60);
    showQueueStatus();
    visualizeQueue();
    
    // Try to enqueue when queue is full
    cout << "PHASE 4: Trying to enqueue when queue is full..." << endl;
    enqueue(70);
    showQueueStatus();
    visualizeQueue();
    
    // Multiple dequeue operations
    cout << "PHASE 5: Dequeue all elements..." << endl;
    while (!isEmpty()) {
        dequeue();
        showQueueStatus();
        visualizeQueue();
    }
    
    // Try to dequeue from empty queue
    cout << "PHASE 6: Trying to dequeue from empty queue..." << endl;
    dequeue();
    
    // Demonstrate circular behavior (conceptually)
    cout << "PHASE 7: Demonstrating queue behavior..." << endl;
    cout << "Note: This is linear queue. For better memory utilization," << endl;
    cout << "we can implement Circular Queue in advanced version." << endl;
    
    enqueue(100);
    enqueue(200);
    dequeue();
    enqueue(300);
    showQueueStatus();
    visualizeQueue();
    
    cout << "=== QUEUE DEMONSTRATION COMPLETED ===" << endl;
    return 0;
}