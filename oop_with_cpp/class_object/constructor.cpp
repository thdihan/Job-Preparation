#include <iostream>

using namespace std;

/*
 * Constructor is a member function that is executed automatically whenever a object is created.
 * Same name as the class.
 * No return type.
 */
class Counter {
    
    private: 
        unsigned int count;
    
    public:
        Counter () : count(0) { //  Initializer list. If multiple variable are initialized then they must be comma separated. Initializer list is the only way to initialize const variable in a class.
            // empty function
        }

        void incrementCount (int val = 1) {
            count += val;
        }

        void showCount () { cout << "Count : " << count << endl; }

        // Descturctor 
        ~Counter () {
            cout << "Object Destroyed" << endl;
        }
};
int main() {
    
    Counter c1;

    c1.showCount();

    c1.incrementCount();
    c1.showCount();

    c1.incrementCount(3);
    c1.showCount();
}
