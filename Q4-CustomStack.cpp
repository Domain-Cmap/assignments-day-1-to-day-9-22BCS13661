#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;

class CustomStack {
private:
    vector<int> stack;
    int capacity;

public:
    CustomStack(int cap) : capacity(cap) {}

    void push(int value) {
        if (stack.size() >= capacity) {
            cout << "Stack Overflow" << endl;
        } else {
            stack.push_back(value);
        }
    }

    int pop() {
        if (stack.empty()) {
            throw runtime_error("Stack Underflow");
        } else {
            int top = stack.back();
            stack.pop_back();
            return top;
        }
    }

    int peek() {
        if (stack.empty()) {
            throw runtime_error("Stack is empty");
        } else {
            return stack.back();
        }
    }

    bool isEmpty() {
        return stack.empty();
    }

    bool isFull() {
        return stack.size() >= capacity;
    }

    int size() {
        return stack.size();
    }

    void printStack() {
        if (stack.empty()) {
            cout << "Stack is empty" << endl;
        } else {
            for (int i = 0; i < stack.size(); i++) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    CustomStack customStack(5);

    customStack.push(10);
    customStack.push(20);
    customStack.push(30);
    customStack.push(40);
    customStack.push(50);
    customStack.push(60); // Should display "Stack Overflow"

    customStack.printStack();

    cout << "Top element: " << customStack.peek() << endl;

    cout << "Popped element: " << customStack.pop() << endl;

    customStack.printStack();

    cout << "Is stack empty? " << (customStack.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (customStack.isFull() ? "Yes" : "No") << endl;
    cout << "Stack size: " << customStack.size() << endl;

    return 0;
}