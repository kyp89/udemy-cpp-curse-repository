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

class Vechicle {
    public:
        Vechicle(const string& name, int capacity):
        _name(name),
        _capcity(capacity)
         {

        }

        int GetCapacity() const {
            return _capcity;
        }

        void SetCapacity(int capacity) {
            if( capacity < 0) {
                return;
            }

            _capcity = capacity;
        }

        void virtual Run() {
            cout << _name << " with " << _capcity << " people running " << endl;
        }
    protected:
        string _name;
    
    private:
        int _capcity;
};

class Car: public Vechicle {
    public:
        Car(const string& name, int capacity, float mileage):
        Vechicle(name, capacity),
        _mileage(mileage) {
    
        }

        void Run() override {
            cout << _name << " with " << GetCapacity() << " people running " << "Mileage:" << _mileage << endl;
        }

        float GetMileage() const {
            return _mileage;
        }
    private:
        float _mileage;
};

int main() {
    std::cout<<"Inheritance"<<endl;

    Vechicle vehicle("Lighhtyer2000", 4);
    vehicle.Run();

    Car car("Toyota", 8, 11.11);
    car.SetCapacity(6);
    car.Run();

    Vechicle& carAsVehicle = car;
    car.Run();
    
    return 0;
}