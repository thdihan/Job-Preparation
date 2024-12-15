#include <iostream>

using namespace std;

class Counter {

    private: 
        static int count;

    public:
        Counter () {
            count++;
        }

        void showCount () {
            cout << count << endl;
        }
};

int Counter::count = 0;
int main() {
    Counter c1;
    c1.showCount();


    Counter c2;
    c2.showCount();
    
    return 0;
}
