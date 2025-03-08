#include <stack>
#include <iostream>
#include <utility> // for std::pair

class MinStack {
private:
    std::stack<std::pair<int, int>> stack; // Pair of (value, current_min)

public:
    MinStack() {
    }

    void push(int val) {
        if (stack.empty()) {
            stack.push({val, val}); // If stack is empty, both value and min are val
        } else {
            int currentMin = stack.top().second; // Get the current minimum
            stack.push({val, std::min(val, currentMin)}); // Push the new value and the new min
        }
    }

    void pop() {
        stack.pop(); // Simply pop the top element
    }

    int top() {
        return stack.top().first; // Return the value part of the top pair
    }

    int getMin() {
        return stack.top().second; // Return the min part of the top pair
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    
    std::cout << "Minimum: " << minStack.getMin() << std::endl; // Returns -3
    minStack.pop();
    std::cout << "Top: " << minStack.top() << std::endl; // Returns 0
    std::cout << "Minimum: " << minStack.getMin() << std::endl; // Returns -2

    return 0;
}