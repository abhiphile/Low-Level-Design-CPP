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
