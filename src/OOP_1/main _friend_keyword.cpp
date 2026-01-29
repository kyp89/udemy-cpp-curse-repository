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

        //Move assignment operator
        IntContainer& operator=(IntContainer&& rhs) noexcept {
            //Unikamy przypisania samego siebie
            //Sprawdzamy czy adresy są takie same
            //self assigment guard. Need to prevent deletion of this.internalPtrValue
            cout << "Move assigment" << endl;
            if(*this == rhs) return *this; 
            //Głęboka kopia
            delete internalPtrValue; //free this memory
            internalPtrValue = rhs.internalPtrValue;//giving ownership to this
            rhs.internalPtrValue = nullptr; //giving up ownership to this
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
        /*
        W C++ słowo kluczowe friend to mechanizm pozwalający wybranym funkcjom lub klasom uzyskać dostęp do prywatnych (private) i 
        chronionych (protected) elementów innej klasy. To taki „kontrolowany wyjątek” od enkapsulacji.
        */

        friend IntContainer operator*(const IntContainer& lhs, const IntContainer& rhs) {
            return IntContainer(lhs.getValue() * rhs.getValue());
        };

         void setValue(int newValue) {
            *internalPtrValue = newValue;
         }

         int getValue() const {
            return *internalPtrValue;
         }

        ~IntContainer() {
            try {
                //cout << "Destructor" << endl;
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

//fAVOR FACILITY FUNCTIONS LIKE THIS INSTEAD OF MEMBER
// IntContainer operator*(const IntContainer& lhs, const IntContainer& rhs) {
//     return IntContainer(lhs.getValue() * rhs.getValue());
// };

IntContainer operator*(const IntContainer& lhs, int rhs) {
    return IntContainer(lhs.getValue() * rhs);
};

IntContainer operator*(int lhs, const IntContainer& rhs) {
    return IntContainer(lhs * rhs.getValue());
};

IntContainer IntContainerFactory(int val) {
    IntContainer ic{val};
    cout << "IntContainerFactory Addres: " << &ic << endl;
    return ic;
}

int main() {

    IntContainer intC1 = 20;
    IntContainer intC2 = 20;
    IntContainer intC3 = intC1 * intC2;

    std::cout << "intC3 :" << intC3.getValue() << endl;

    intC3 = intC1 * 4;

    std::cout << "intC3 :" << intC3.getValue() << endl;

    intC3 = 5 * intC1;

    std::cout << "intC3 :" << intC3.getValue() << endl;

    return 0;
}