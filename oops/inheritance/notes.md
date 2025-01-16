### Inheritance in C++

**Inheritance** allows a class (derived class) to inherit properties and behaviors (methods) from another class (base class). This helps in code reuse and establishing a hierarchy among classes.

#### 1. **Basic Syntax of Inheritance**

Here’s a simple example to explain how inheritance works:

```cpp
#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void bark() {
        cout << "The dog barks." << endl;
    }
};

int main() {
    Dog dog;
    dog.eat();  // Calling base class function
    dog.bark(); // Calling derived class function
    return 0;
}
```

In this example:
- `Animal` is the base class.
- `Dog` is the derived class that inherits from `Animal`.
- The derived class `Dog` can use the method `eat()` defined in the base class `Animal`.

#### 2. **Types of Inheritance**

C++ supports different types of inheritance:
- **Single Inheritance**: A class inherits from one base class.
- **Multiple Inheritance**: A class inherits from more than one base class.
- **Multilevel Inheritance**: A class is derived from a class which is also derived from another class.
- **Hierarchical Inheritance**: Multiple classes inherit from a single base class.
- **Hybrid Inheritance**: A combination of two or more types of inheritance.

Let’s look at each type with examples.

---

### Single Inheritance

```cpp
#include <iostream>
using namespace std;

class Vehicle {
public:
    void display() {
        cout << "This is a vehicle." << endl;
    }
};

class Car : public Vehicle {
public:
    void carType() {
        cout << "This is a car." << endl;
    }
};

int main() {
    Car myCar;
    myCar.display();
    myCar.carType();
    return 0;
}
```

### Multiple Inheritance

```cpp
#include <iostream>
using namespace std;

class Engine {
public:
    void engineType() {
        cout << "This is a petrol engine." << endl;
    }
};

class Body {
public:
    void bodyType() {
        cout << "This is a sedan body." << endl;
    }
};

class Car : public Engine, public Body {
public:
    void display() {
        cout << "This is a car with specific engine and body type." << endl;
    }
};

int main() {
    Car myCar;
    myCar.engineType();
    myCar.bodyType();
    myCar.display();
    return 0;
}
```

### Multilevel Inheritance

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

class Mammal : public Animal {
public:
    void hasFur() {
        cout << "This mammal has fur." << endl;
    }
};

class Dog : public Mammal {
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
```

### Hierarchical Inheritance

```cpp
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
```

### Hybrid Inheritance

```cpp
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
```

#### 3. **Access Specifiers in Inheritance**

- **Public Inheritance**: Public and protected members of the base class remain public and protected in the derived class.
- **Protected Inheritance**: Public and protected members of the base class become protected in the derived class.
- **Private Inheritance**: Public and protected members of the base class become private in the derived class.

```cpp
#include <iostream>
using namespace std;

class Base {
protected:
    void display() {
        cout << "Display of Base" << endl;
    }
};

class DerivedPublic : public Base {
public:
    void show() {
        display();  // Accessible because it's public inheritance
    }
};

class DerivedProtected : protected Base {
public:
    void show() {
        display();  // Accessible because it's protected inheritance
    }
};

class DerivedPrivate : private Base {
public:
    void show() {
        display();  // Accessible because it's private inheritance
    }
};

int main() {
    DerivedPublic objPublic;
    objPublic.show();
    
    DerivedProtected objProtected;
    objProtected.show();
    
    DerivedPrivate objPrivate;
    objPrivate.show();

    return 0;
}
```
