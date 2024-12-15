#include <iostream>

using namespace std;

class Distance {
    private: 
        float inch, feet;

    public: 
        Distance () : inch (0.0), feet(0.0) {}
        Distance (float ft, float in) : inch (in), feet (ft) {}

        void setDistance (float ft, float in) {
            inch = in;
            feet = ft;
        }

        void showDistance () { cout << "Feet: " << feet << "Inch : "<< inch << endl; }

        void addDist (Distance, Distance); // Only Declaration
};

// Member function defined outside the class
// :: is called scope-resolution-operator, a way to specify what class something is associated with.
void Distance::addDist (Distance d1, Distance d2) {
    feet = 0;
    inch  = d1.inch + d2.inch;

    if(inch >= 12.0) {
        inch -= 12.0;
        feet++;
    }

    feet += (d1.feet + d2.feet);

    cout << feet << "ft "<< inch <<"in " << endl;
} 
int main() {
    Distance d1 (1, 2);
    Distance d2(1, 10);

    Distance d3;
    d3.addDist(d1, d2);

    // Both using "DEFAULT COPY CONSTRUCTOR" 
    
    Distance d4 (d1);
    Distance d5 = d4;

    d4.showDistance();
    d5.showDistance();
    
    return 0;
}
