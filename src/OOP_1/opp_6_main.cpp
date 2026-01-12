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

class IntContainer {
    public:
        IntContainer():
            internalPtrValue(new int(0)) {
                cout << "Default contructor" << endl;
                cout << "Internal Value: " << *internalPtrValue << endl;
            }
        
        IntContainer(int value): 
         internalPtrValue(new int(value)) {
            cout << "One Parameter contructor" << endl;
            cout << "Internal Value: " << *internalPtrValue << endl;
         }
        
         //Shallow copy
         //Move contrutor
        IntContainer(IntContainer&& other):
            internalPtrValue(other.internalPtrValue) {
            other.internalPtrValue = nullptr;
            cout << "Move constructor" << endl;
            cout << "Internal Value: " << *internalPtrValue << endl; 

         }

         //Copy construktor
         IntContainer(const IntContainer& intContainer) noexcept :
            internalPtrValue(new int(*intContainer.internalPtrValue)) {
                cout << "copy contructor" << endl;
                cout << "Internal Value: " << *internalPtrValue << endl;
        }

        //Copy assignment operator
        IntContainer& operator=(const IntContainer& rhs){
            //Unikamy przypisania samego siebie
            //Sprawdzamy czy adresy są takie same
            if(*this == rhs) return *this; 
            //Głęboka kopia
            *internalPtrValue = rhs.getValue();
            return *this;
        }
        //Nadpisujemy operator ==
        bool operator==(const IntContainer& intContainer) {
            if(internalPtrValue == intContainer.internalPtrValue) return true;
            if(getValue() == intContainer.getValue()) return true;

            return false;
        }

        bool operator!=(const IntContainer& intContainer) {
            return !(*this == intContainer);
        }

        void operator+=(const IntContainer& intContainer) {
            *internalPtrValue = getValue() + *intContainer.internalPtrValue;
        }

        void operator-=(const IntContainer& intContainer) {
            *internalPtrValue = getValue() - *intContainer.internalPtrValue;
        }

        void operator*=(const IntContainer& intContainer) {
            *internalPtrValue = getValue() * *intContainer.internalPtrValue;
        }

        void operator/=(const IntContainer& intContainer) {
            *internalPtrValue = getValue() / *intContainer.internalPtrValue;
        }

         void setValue(int newValue) {
            *internalPtrValue = newValue;
         }

         int getValue() const {
            return *internalPtrValue;
         }

        ~IntContainer() {
            try {
                cout << "Destructor" << endl;
                // cout << "INT Address: " << &internalPtrValue << endl;
                // cout << "INT Value: " << *internalPtrValue << endl;
                delete internalPtrValue;
            }
            catch (...) {
                cout << "Caught an unknown exception!" << endl;
            }
        }

    private:
        int* internalPtrValue;
};

IntContainer IntContainerFactory(int val) {
    IntContainer ic{val};
    cout << "IntContainerFactory Addres: " << &ic << endl;
    return ic;
}

int main() {

    IntContainer intC1 = 20;
    IntContainer intrC2 = intC1; //Uruchamia defaultowy konstrutor kopiowania.
    cout << intrC2.getValue() << endl;

    IntContainer intC3 = std::move(IntContainerFactory(28));
    cout << "intC3 Addres: " << &intC3 << endl;
    cout << "GET Value: " << intC3.getValue() << endl;

    if(intC1 == intC3) {
        cout << "intC1 and intC3 are equal" << endl;
    }else {
        cout << "intC1 and intC3 are not equal" << endl;
    }

    IntContainer intC4 = 20;

    if(intC1 == intC4) {
        cout << "intC1 and intC4 are equal" << endl;
    }else {
        cout << "intC1 and intC4 are not equal" << endl;
    }

    if( intC4 != intC3) {
        cout << "intC4 and intC3 are not equal" << endl;
    }

    IntContainer intC5 = 25;

    intC5 += intC4;

    cout << "intC5 value is: " << intC5.getValue() << endl;

    IntContainer intC6 = 25;

    intC6 *= intC4;

    cout << "intC6 value is: " << intC6.getValue() << endl;

    IntContainer intC7 = 25;

    intC7 /= intC4;

    cout << "intC7 value is: " << intC7.getValue() << endl;

    return 0;
}