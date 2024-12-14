#include <iostream>

using namespace std;
/*
 * The central idea of OOP is placing functions and data togather into a single entity.
 * Key feature of OOP is Data Hiding: means hiding data from part of the program that do not need to access it.
 */
// Simple Class and object.
class SimpleClass {

  private: // access modifier 
  
    int someData; // Member Data

  public: // Access modifier

    // Member functions
    void setData (int data) {
      someData = data;
    }
    void showData () {
      cout << "Value: " << someData <<endl;
    }
};

/*
* Dot operator is also called class member access operator.
* Some object-oriented languages refer to calls to member functions as "messages".
*/

int main() {

  SimpleClass c1, c2;
  
  c1.setData(1); 
  c2.setData(2);

  c1.showData();
  c2.showData();

}
