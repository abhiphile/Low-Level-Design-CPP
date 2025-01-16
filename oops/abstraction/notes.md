### Abstraction in C++

**Abstraction** is a fundamental concept in object-oriented programming (OOP) that allows you to hide the internal implementation details of a class and expose only the essential features. This makes the code easier to manage and reduces complexity by focusing only on what an object does instead of how it does it.

In C++, abstraction is achieved using:
1. **Abstract Classes**
2. **Pure Virtual Functions**

---

### 1. **Abstract Classes**

An **abstract class** is a class that cannot be instantiated on its own and usually serves as a base class. It is designed to be inherited by other classes. Abstract classes in C++ contain at least one **pure virtual function**.

A **pure virtual function** is a function declared within a class and is meant to be overridden by derived classes. It is declared by using the `= 0` syntax.

#### Example of an Abstract Class

```cpp
#include <iostream>
using namespace std;

// Abstract class
class Animal {
public:
    // Pure virtual function
    virtual void sound() = 0;

    void eat() {
        cout << "This animal eats food." << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "The dog barks." << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "The cat meows." << endl;
    }
};

int main() {
    Dog dog;
    Cat cat;

    dog.sound();  // Output: The dog barks.
    dog.eat();    // Output: This animal eats food.

    cat.sound();  // Output: The cat meows.
    cat.eat();    // Output: This animal eats food.

    // Animal animal; // Error: Cannot instantiate abstract class
    return 0;
}
```

In this example:
- `Animal` is an abstract class because it contains a pure virtual function `sound()`.
- `Dog` and `Cat` are derived classes that override the `sound()` function to provide specific implementations.

---

### 2. **Pure Virtual Functions**

A **pure virtual function** is a function that is declared within a base class and set to `= 0`. It does not have an implementation in the base class. Derived classes must provide their own implementation for the pure virtual function.

#### Key Points:
- A class with at least one pure virtual function is considered an abstract class.
- Abstract classes cannot be instantiated.
- Derived classes must override the pure virtual function to become concrete classes that can be instantiated.

#### Another Example with Pure Virtual Functions

```cpp
#include <iostream>
using namespace std;

// Abstract class
class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;
    virtual double area() = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    void draw() override {
        cout << "Drawing a circle." << endl;
    }

    double area() override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    void draw() override {
        cout << "Drawing a rectangle." << endl;
    }

    double area() override {
        return length * width;
    }
};

int main() {
    Shape* shape1 = new Circle(5.0);
    Shape* shape2 = new Rectangle(4.0, 6.0);

    shape1->draw();  // Output: Drawing a circle.
    cout << "Area of circle: " << shape1->area() << endl;  // Output: Area of circle: 78.5397

    shape2->draw();  // Output: Drawing a rectangle.
    cout << "Area of rectangle: " << shape2->area() << endl;  // Output: Area of rectangle: 24

    delete shape1;
    delete shape2;

    return 0;
}
```

In this example:
- `Shape` is an abstract class with two pure virtual functions: `draw()` and `area()`.
- `Circle` and `Rectangle` are concrete classes that provide specific implementations for these pure virtual functions.

---

### Benefits of Abstraction

1. **Code Reusability**: Abstract classes and functions promote code reuse by allowing derived classes to inherit common behavior.
2. **Modularity**: Abstract classes allow for modular code, making it easier to update and maintain.
3. **Encapsulation**: By hiding the implementation details, abstraction ensures that only the essential features are exposed to the users of the class.
