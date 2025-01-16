### Polymorphism in C++

**Polymorphism** is one of the core concepts of object-oriented programming. It allows objects to be treated as instances of their parent class rather than their actual class. The word polymorphism means "many forms." In C++, polymorphism allows you to invoke derived class methods through a base class reference or pointer, facilitating a clean and extendable code structure.

There are two types of polymorphism in C++:
1. **Compile-time Polymorphism** (Static Polymorphism)
2. **Runtime Polymorphism** (Dynamic Polymorphism)


---

### 1. **Compile-time Polymorphism**

Compile-time polymorphism is achieved using **function overloading** and **operator overloading**.

#### Function Overloading

Function overloading allows multiple functions with the same name but different parameters to be defined. The correct function to be invoked is determined at compile-time.

```cpp
#include <iostream>
using namespace std;

class Print {
public:
    void show(int i) {
        cout << "Integer: " << i << endl;
    }
    
    void show(double d) {
        cout << "Double: " << d << endl;
    }
    
    void show(string s) {
        cout << "String: " << s << endl;
    }
};

int main() {
    Print printObj;
    
    printObj.show(5);        // Output: Integer: 5
    printObj.show(5.5);      // Output: Double: 5.5
    printObj.show("Hello");  // Output: String: Hello
    
    return 0;
}
```

#### Operator Overloading

Operator overloading allows you to redefine the behavior of operators for user-defined types.

```cpp
#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    
    // Overloading the '+' operator
    Complex operator + (const Complex &obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }
    
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3.0, 4.0), c2(1.5, 2.5);
    Complex c3 = c1 + c2;  // Using overloaded '+' operator
    c3.display();          // Output: 4.5 + 6.5i
    
    return 0;
}
```

---

### 2. **Runtime Polymorphism**

Runtime polymorphism is achieved using **inheritance** and **virtual functions**. The function to be called is determined at runtime using **pointers** or **references** to base class objects.

#### Virtual Functions

A **virtual function** is a function that is declared in the base class and is meant to be overridden in the derived class. The `virtual` keyword is used to declare a virtual function.

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    Animal* animalPtr;
    Dog dog;
    Cat cat;
    
    animalPtr = &dog;
    animalPtr->sound();  // Output: Dog barks

    animalPtr = &cat;
    animalPtr->sound();  // Output: Cat meows

    return 0;
}
```

In this example:
- `sound()` is a virtual function in the base class `Animal`.
- The derived classes `Dog` and `Cat` override the `sound()` function.
- Using a pointer to `Animal`, we can invoke the overridden `sound()` function at runtime.

#### Abstract Class and Virtual Functions

An abstract class is often used as a base class with pure virtual functions. This ensures that derived classes provide specific implementations for these functions.

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a rectangle" << endl;
    }
};

int main() {
    Shape* shapePtr;
    Circle circle;
    Rectangle rectangle;
    
    shapePtr = &circle;
    shapePtr->draw();  // Output: Drawing a circle

    shapePtr = &rectangle;
    shapePtr->draw();  // Output: Drawing a rectangle

    return 0;
}
```

---

### Summary of Polymorphism

- **Compile-time Polymorphism**: Achieved through function overloading and operator overloading. It is determined at compile-time which function or operator to invoke.
- **Runtime Polymorphism**: Achieved using inheritance and virtual functions. The function to be invoked is determined at runtime.
