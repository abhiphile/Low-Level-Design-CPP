#include<iostream>
using namespace std;

// Abstract Class
class Vechile{
    public:
    virtual void draw() = 0; // Pure virtual function
};

// Derived class
class Car : public Vechile{
    public:
    void draw () override{
        cout<<"Draw a car"<<endl;
    }
};

int main(){
    Car myCar;
    myCar.draw();
    return 0;
}

