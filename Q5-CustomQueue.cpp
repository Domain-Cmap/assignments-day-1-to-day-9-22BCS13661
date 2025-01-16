#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;

class CustomQueue {
private:
    vector<int> queue;
    int capacity;

public:
    CustomQueue(int cap) : capacity(cap) {}

    void enqueue(int value) {
        if (queue.size() >= capacity) {
            cout << "Queue Overflow" << endl;
        } else {
            queue.push_back(value);
        }
    }

    int dequeue() {
        if (queue.empty()) {
            throw runtime_error("Queue Underflow");
        } else {
            int front = queue.front();
            queue.erase(queue.begin());
            return front;
        }
    }

    int front() {
        if (queue.empty()) {
            throw runtime_error("Queue is empty");
        } else {
            return queue.front();
        }
    }

    bool isEmpty() {
        return queue.empty();
    }

    bool isFull() {
        return queue.size() >= capacity;
    }

    int size() {
        return queue.size();
    }

    void printQueue() {
        if (queue.empty()) {
            cout << "Queue is empty" << endl;
        } else {
            for (int i = 0; i < queue.size(); i++) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    CustomQueue customQueue(5);

    customQueue.enqueue(10);
    customQueue.enqueue(20);
    customQueue.enqueue(30);
    customQueue.enqueue(40);
    customQueue.enqueue(50);
    customQueue.enqueue(60); // Should display "Queue Overflow"

    customQueue.printQueue();

    cout << "Front element: " << customQueue.front() << endl;

    cout << "Dequeued element: " << customQueue.dequeue() << endl;

    customQueue.printQueue();

    cout << "Is queue empty? " << (customQueue.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is queue full? " << (customQueue.isFull() ? "Yes" : "No") << endl;
    cout << "Queue size: " << customQueue.size() << endl;

    return 0;
}