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

class Student
{
    public:
        //Constructors. RAII - zarządzanie zasobami w klasie
        Student(const string& _name, int id):
        name(string(_name)),
        ID(id){
            year = 0;
        };
        Student(const string& _name, int id, int _year):
        Student(_name, id){
            this->year = _year;
        };
        //Constructors
        //Members
        string name;
        //Members
        //Members functions
        
        void print() const {
            cout << "Name:" << name << ", ID:" << ID << ", Year:" << year << endl;
            
        };
        
        void IncrementYear(){
            year++;
            cout << name << ":" << year << endl;
            // if(year > 4){
            //     cout << name << "graduated" << endl;
            // }
            switch(year){
                case 1:
                    cout << name << " is freashman" << endl;
                    break;
                case 2:
                    cout << name << " is 2nd year" << endl;
                    break;
                case 3:
                    cout << name << " is in 3nd year" << endl;
                    break;
                case 4:
                     cout << name << " is last year" << endl;
                    break;
                default:
                    cout << name << ": graduated" << endl;
                    break;
            }
        }
        
        bool IsGraduated() const {
            return year > 4;
        }
        //setter
        //Jeśli właściwość ID jest const to nie można jej modyfikować
        // void SetId(int newID){
        //     if(newID < 0){
        //         cout << "Wrong Value " << endl;
        //         return;
        //     }
            
        //     ID = newID;
        // }
        //getter
        //const można dodać jeśli nie zmieniamy nic w ciele funckji
        int GetID() const {
            return ID;
        }
        //Members functions
        //Desctructor
        ~Student(){
            cout << "Student: " << name << " is destructed" << endl;
        }
    private:
        //Private members
        int secrete;
        int year;
        const int ID;
        //Private members
};

int main()
{
    std::cout<<"Class";
    
    Student student("Jhony1", 123);
    student.print();
    student.IncrementYear();
    cout << "-------------------------" << endl;
    Student student2("Jhony2", 123, 3);
    student2.print();
    student2.IncrementYear();
    cout << "-------------------------" << endl;
    Student student3("Jhon3y", 123);
    cout << "-------------------------" << endl;
    while(student3.IsGraduated() == false){
        student3.IncrementYear();
    }
    cout << "-------------------------" << endl;
    
    Student student4("Jhony4", 123);
    student4.print();
    //student4.SetId(33);
    student4.print();
    cout << "-------------------------" << endl;
    return 0;
}