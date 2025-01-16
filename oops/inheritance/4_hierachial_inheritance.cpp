// Multiple classes inherits from a single base class

#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "The dog barks." << endl;
    }
};

class Cat : public Animal {
public:
    void meow() {
        cout << "The cat meows." << endl;
    }
};

int main() {
    Dog dog;
    Cat cat;

    dog.eat();
    dog.bark();

    cat.eat();
    cat.meow();

    return 0;
}
