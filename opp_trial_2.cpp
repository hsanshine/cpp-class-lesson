#include <iostream>
#include <list>
using namespace std;

class Person {
private:  // will only be accessed by methods inside this class. someone cannot change this without having a method
    // to carry out this change. Like the only way to create a name for a channel is through the constructors when 
    //the channel object is being created for the first time. i type faster when i fold my hands.
    // so if you want to set the name now.. i can give you access if i wanted through a get_name method and a set_name
    int Age;
    list<string> Friends; // a list of their friends names
protected: //protected properties are private but can be accessed by methods in derived classes.
    string Name;
    int Popularity; // this depends the number of lives saved
public:
    // Person constructor called when an object of the Person class is being created.
    Person(string name, int age) {
        //we assing to the class variables because this method has access to them as they are in the same scope
        Name = name;
        Age = age;
        Popularity = 0;
    }

    void getInfo() {
        cout << Name << " is " << Age << " years old." << endl;
        cout << Name << " has " << Friends.size() << " friends. " << endl;
        cout << "The friends are: "<<endl;
        for (string buddy : Friends) {
            cout << buddy << endl;
        }
        cout << endl << endl;
    }

    void addFriend(string buddy) {
        Friends.push_back(buddy);
    }

    string getName() {
        return Name;
    }
    void setName(string newName) {
        Name = newName;
    }

    void checkPopularity() {
        cout << Name << " has a populariy level of : " << Popularity << endl << endl << endl;
    }
   

};

// a derived class called alien that inherites from the base class called person
class Alien : public Person { //whatever is public in person will also be public in Alien class
public:
    // a constructor should be public
    Alien(string name, int age) : Person(name, age) { 
        // the  constructor in Person class will handle this for us
    }

    void changeColor() {
        cout<< Name << "is changing his skin color now...to go help out a human in trouble" << endl;
        Popularity++; // helping a human increases his popularity.
    }

};

//super hero class derives from the  person class just like the alien class by polymorphisim
class SuperHero : public Person {
public:
    SuperHero(string name, int age) : Person(name, age) {
        // person constructor is used to construct this super hero
    }
    void changeColor() {
        //the name comes from the name property in the Person base class
        cout << Name << "is changing his color to join the other super heros in a mission\n";
        Popularity++;// popularity increases when he does missions to help out humans.
    }
};

int main()
{
    Person Person1("Hamza", 22);
    Person Person2("Wina", 21);
    Person Person3("Micheal", 25);
    Alien Alien1("Jimmy", 2100);
    SuperHero superHero1("Tony Stark", 37); // create a super hero object., contructors must be public

    //testing class pointers to objecsts.
    Person* personPointer1 = &Alien1; //we give this pointer the address of alien1
    Person* personPointer2 = &superHero1; ///we give this pointer to a person the address of superHero1

   

    // alien is a class the inherited from the person class but can also change colors
    Alien1.addFriend("Black Panther.");
    Alien1.addFriend("Maradona.");
    Alien1.addFriend("Micheal Jackson.");
    Alien1.changeColor();
    Alien1.changeColor();
    Alien1.getInfo(); // defined in the person class
    personPointer1->checkPopularity();
    
    
    
    superHero1.addFriend("Captain America");
    superHero1.addFriend("Hulk");
    superHero1.addFriend("Wonder Woman");
    superHero1.addFriend("Spider Man");
    superHero1.changeColor();
    superHero1.changeColor();
    superHero1.changeColor();
    superHero1.changeColor();
    superHero1.getInfo(); // was defined in the person class
    personPointer2->checkPopularity(); // -> is read as dot but its how we access data using pointers.
    //the dot is used for data access off the actual var like an obj or a structure member


    Person1.addFriend("Wina");
    Person1.addFriend("Robin");
    Person1.addFriend("Micheal");
    Person1.addFriend("Dullah");
    Person1.addFriend("Luis");
    Person1.addFriend("Motta");

    Person2.addFriend("Escobar");
    Person2.addFriend("Dullah");
    Person2.addFriend("Mohammed");
    Person2.addFriend("Nelly");
    Person2.addFriend("Luis");
    Person2.addFriend("Niger Guy");
    Person2.addFriend("Hamza");

    Person3.addFriend("Aloy");
    Person3.addFriend("Davis");
    Person3.addFriend("Urtnatsan");
    Person3.addFriend("Coders");
    
    Person1.getInfo();
    Person2.getInfo();
    Person3.getInfo();


    //now you can only access those private attributes through these methods and only if i provide them.
    //if i dont give you access methods you will never has access to them.
    cout << "obj 1 has the name: " << Person1.getName() << endl;
    Person1.setName("Kyamanywa Hamza");
    cout << "obj1 now has the name: " << Person1.getName() << endl;


    system("pause>0");
}

