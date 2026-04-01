#include <iostream>
#include <string>


int main() {

    //Declare String
    std::string name = "SOME NAME1234567890";
    std::string n2("SOME NAME");
    std::string n3(name); //Copy constructur

    std::string n4 { 'S', 'O', 'M', 'E', ' ' };//Constructur based on chars list
    std::string last(name, 6, 6);
    std::string line(20, '-');
    std::string reverse(name.rbegin(), name.rend());

    std::cout << "String 1: " << name << std::endl;
    std::cout << "String 2: " << n2 << std::endl;
    std::cout << "String 3: " << n3 << std::endl;
    std::cout << "String 4: " << n4 << std::endl;
    std::cout << "String 5: " << last << std::endl;
    std::cout << "String 6: " << line << std::endl;
    std::cout << "String 7: " << reverse << std::endl;

    //Finding strings
    std::size_t pos = name.find(n4);//Szuka całości n4 w name
    if(pos != std::string::npos) {
        std::cout << "Found first name at:" << pos << std::endl;
    }
    std::string helloWorld = "Hello, How are you";
    std::cout << "Coma at: " << helloWorld.find(',') << std::endl;

    std::string about = "is a super hero!!!";
    name.push_back(' ');
    for(char c: about) {
        name.push_back(c);
    }

    std::cout << "String 1: " << name << std::endl;

    //Insert inot string
    name.insert(0, "Someone is super:");
    std::cout << "String 1: " << name << std::endl;


    //Replace some strings:
    pos = name.find("hero");
    std::string hero = "hero";
    std::string badGuy = "Bad GUY!!!";

    name.replace(pos, hero.length(), badGuy);

    std::cout << "String 1: " << name << std::endl;

    std::string toEarse = "Someone is super:";
    pos = name.find(toEarse);
    name.erase(pos, toEarse.length());
    name.insert(pos, "YOU ARE :");

    std::cout << "String 1: " << name << std::endl;

    return 0;
}