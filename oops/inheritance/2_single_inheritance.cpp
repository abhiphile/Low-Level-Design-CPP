// A class inherits from a single base class

# include<iostream>
using namespace std;

class Vechile {
    public:
    void display(){
        cout<<"This is a vechile"<<endl;
    }
};

class Car:public Vechile{
    public:
    void carType(){
        cout<<"This is a Car !"<<endl;
    }
};

int main(){
    Car newCar;
    newCar.carType();
    newCar.display();
    return 0;
}