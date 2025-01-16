# include<iostream>
using namespace std;

class Complex{
private:
    double real, img;
public:
    Complex(double r=0, double i=0) : real(r), img(i){};
    Complex operator + (const Complex &obj){
        return Complex(real+obj.real, img+obj.img);
    }
    void display(){
        cout<<real<<" + "<<img<<"i\n";
    }
};

int main(){
    Complex cp1(2, 3);
    Complex cp2(3, 4.4);
    cp1.display();
    cp2.display();
    Complex cp3 = cp1 + cp2;
    cp3.display();
}