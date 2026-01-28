/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

template<typename T>
class DynamicNumber {
    public:
        DynamicNumber():
        ptr(new T){}

        explicit DynamicNumber(const T& value):
        ptr(new T(value)){}

        //BIG Five
        ~DynamicNumber() {
            delete ptr;
        }
        //Copy constructor - deep copy
        template<typename otherT>
        DynamicNumber(const DynamicNumber<otherT>& other):
        ptr(new T((T)other.getValue())){

        }

        DynamicNumber(const DynamicNumber& other):
        ptr(new T(other.getValue())){

        }

        //move constructor - shallow copy
        //Przenosi posiadacza wskaźnika do nowego obiektu
        DynamicNumber(DynamicNumber&& other):
        ptr(other.ptr){
            other.ptr = nullptr;
        }

        //Operator kopiowania
        DynamicNumber& operator=(const DynamicNumber& other) {
            if(*this == other) return *this;  //self assignment check
            if(ptr == nullptr) {
                ptr = new T(other.getValue());
            }else {
                *ptr = other.getValue();
            }
            return *this;
        }
        //operator przenoszenia
        DynamicNumber& operator=(DynamicNumber&& other){
            if(*this == other) return *this;

            delete ptr;
            ptr = other.ptrl;
            other.ptr = nullptr;
            
            return *this;
        }

        //operator ==
        bool operator==(const DynamicNumber& other) const {
            if(ptr == other.ptr) return true;
            if(getValue() == other.getValue()) return true;
            return false;
        } 

        T getValue() const {
            if(ptr)
                return *ptr;
            
            return T{};
        }

        void setValue(const T& other) {
            *ptr = other;
        }

    private:
        T* ptr;
};


int main() {

    DynamicNumber<float> dynamicNumber1;

    std::cout << "dynamicNumber1 value: " << dynamicNumber1.getValue() << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;

    DynamicNumber<float> dynamicNumber2(1.23);

    std::cout << "dynamicNumber2 value: " << dynamicNumber2.getValue() << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;

    DynamicNumber<float> dynamicNumber3 = dynamicNumber2;

    std::cout << "dynamicNumber3 value: " << dynamicNumber3.getValue() << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;

    dynamicNumber3.setValue(33.33);

    std::cout << "dynamicNumber3 value: " << dynamicNumber3.getValue() << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;

    DynamicNumber<float> dynamicNumber4 = std::move(dynamicNumber2);

    std::cout << "dynamicNumber2 value: " << dynamicNumber2.getValue() << std::endl;
    std::cout << "dynamicNumber4 value: " << dynamicNumber4.getValue() << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;

    dynamicNumber2 = dynamicNumber4;

    std::cout << "dynamicNumber2 value: " << dynamicNumber2.getValue() << std::endl;
    std::cout << "dynamicNumber4 value: " << dynamicNumber4.getValue() << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;

    DynamicNumber<int> dynamicNumber5(100);
    std::cout << "dynamicNumber5 value: " << dynamicNumber5.getValue() << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;

    DynamicNumber<float> dynamicNumber6 = dynamicNumber5;
    std::cout << "dynamicNumber5 value: " << dynamicNumber5.getValue() << std::endl;
    std::cout << "dynamicNumber6 value: " << dynamicNumber6.getValue() << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    return 0;
}