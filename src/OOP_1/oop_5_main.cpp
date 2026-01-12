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

//klasa Vechicle jest konceptem abstrakcyjnym
//Jeśli klasa ma jedną "czytą" wirtualną metodę to oznacza automatycznie że 
//klasa jest abstrakcyjna
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
        //Czysta metoda virtualna może być nadpisana prze klasy pochodne
        //Taka metoda świadczy że klasa jest abstrakcyjna
        void virtual Run() = 0;
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

    //Z klas abstrakcyjnych nie można tworzyć obiektów
    //Vechicle vehicle("Lighhtyer2000", 4);
    //vehicle.Run();

    Car car("Toyota", 8, 11.11);
    car.SetCapacity(6);

    //Wskaźnik
    Vechicle* carAsVehicle = &car;
    //Referencja
    Vechicle& carAsVehicle2 = car;

    car.Run();
    carAsVehicle->Run();
    carAsVehicle2.Run();
    
    return 0;
}