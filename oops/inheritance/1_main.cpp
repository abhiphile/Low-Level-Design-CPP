// 1. Basics of inheritance in cpp

#include <iostream>
using namespace std;

// Base Class

class Animal{
    public:
    void eat(){
        cout<<"This Animal Eats Food !"<<endl;
    }
};

// Derived Class

class Dog:public Animal{
    public:
    void bark(){
        cout<<"Dog Barks !!"<<endl;
    }
};


int main(){
    Dog newDog;
    newDog.eat(); // Eat method is inherited from Animal class
    newDog.bark();
    return 0;
}