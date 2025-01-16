#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

class Mammal {
public:
    void hasFur() {
        cout << "This mammal has fur." << endl;
    }
};

class Dog : public Animal, public Mammal {
public:
    void bark() {
        cout << "The dog barks." << endl;
    }
};

int main() {
    Dog dog;
    dog.eat();
    dog.hasFur();
    dog.bark();
    return 0;
}
