/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

class MyClass {
    public:
        MyClass();
        ~MyClass();

        static int GetCount();
    private:
        int member;
        static int count;
};

int MyClass::count = 1;

MyClass::MyClass():
    member(0) {
    MyClass::count++;
    std::cout << "MyClass static count: " << count << std::endl;
}

MyClass::~MyClass() {
    MyClass::count--;
    std::cout << "MyClass static count: " << count << std::endl;
}

int MyClass::GetCount() {
    return MyClass::count;
}

int main() {
    MyClass myclass_1;
    MyClass myclass_2;

    std::cout << "Finally MyClass static count: " << MyClass::GetCount() << std::endl;

    return 0;
}