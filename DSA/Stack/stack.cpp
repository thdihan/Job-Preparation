#include <iostream>

using namespace std;
/**
 * Stack Implementation
 */
class Stack {
    protected: 
        int *elements;
        int capacity;
        int topIdx;
    public:
        Stack(int capacity) {
            this->capacity = capacity;
        };
        void push(int val);
        int pop();
        int top();
        bool isEmpty();
        bool isFull();

};

class StackUsingArray : Stack{ 
    public:
        StackUsingArray(int capacity) : Stack(capacity){
            this->elements = new int[capacity];
            this->topIdx = -1;
        }

        void push(int val) {
            if(topIdx + 1 == capacity) {
                cout << "[LOG] : Capacity Full." <<endl;
            }
            elements[++topIdx] = val;
        }


};
int main() {

}