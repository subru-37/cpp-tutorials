#include <iostream>
#include <vector>
#include <string>

using namespace std;

class AbstractE{
   public:
        bool AskForPromotion(int Age){
            if (Age>30) return true;
            else return false;
        }
};

class Employee: public AbstractE{
    private:
        string Company;
        int Age;
    protected:
        string Name; 
    public:
        // setter of encapsulation
        void setName(string name){
            Name = name;
        }
        // getter of encapsulation
        string getName(){
            return Name;
        }
        void setCompany(string company){
            Company = company;
        }
        // getter of encapsulation
        string getCompany(){
            return Company;
        }
        void setAge(int age){
            if (age>=18) Age = age;
            else cout<<"Person is a minor"<<endl;
        }
        // getter of encapsulation
        int getAge(){
            return Age; 
        }
        
        void introduce(){
            cout<<"My Name is "<<Name<<" and I work at "<<Company<<" Age - "<<Age<<endl;
        }

        Employee(string name, string company, int age){
            Name = name;
            Company = company;
            Age = age;
        }

        void displayBonus() {
            bool bonus = AbstractE::AskForPromotion(Age);
            cout << "Employee Bonus Eligibility: " << bonus << endl;
        }

        virtual void Work(){
            cout<<Name<<" is Working "<<endl;
        }
};

// Access Modifiers
// Private by default 
// private, public and protected class modifiers 

// private can't be accessed outside of my class
// public can be accessed outside of class
// protected variables can be accessed by derived or child classes

// Constructors have same Name as class, do not have any return type, not even void, and it must be public

// ENcapsulation, abstraction, inheritance, polymorphism

// ENcapsulation define how users can access and modify our grouped data , thereby limiting direct access

// inheritance involves base (super class or parent class) and derived class (child or sub class) 

// derived class will have all the attributes of a parent class and of its own too 

// developer is derived class, employee is parent class


class Developer: public Employee{
    public:
        string FavPLang;

        Developer(string name, string company, int age, string favlang ):Employee(name, company, age){
            FavPLang = favlang;
        }
        void FixBug(){
            cout<<getName()<<" Fixed bugs using "<< FavPLang<<endl;
        }
        void Work(){
            cout<<Name<<" is writing code in "<<FavPLang<<endl;
        }
};

class Instructor: public Employee{
    public: 
        string Subject;
        void prepare(){
            cout<<Name<<" is Preparing "<<Subject<<endl;
        }
        Instructor(string name, string company, int age, string subject): Employee(name, company, age){
            Subject = subject;
        }
        void Work(){
            cout<<Name<<" is teaching in "<<Subject<<endl;
        }
};

// Polymorphism
// The most common use of polymorphism is when a parent class reference is used to refer 
// a child class object

// aka a parent class pointer able to access child class attributes 

int main(){
    // vector<Employee> myEmployees;
    // Employee temp1 = Employee("Subramani E", "Alemeno", 21);
    // Employee temp2 = Employee("Dad", "Amazon", 50);

    // myEmployees.push_back(temp1);
    // myEmployees.push_back(temp2);

    // myEmployees[0].displayBonus();
    // myEmployees[1].displayBonus();

    Developer mydev = Developer("Subru", "Amazon", 21, "C++");
    Instructor myteacher = Instructor("Subru", "Amazon", 21, "React.Ts");

    mydev.Work();
    myteacher.Work();

    Employee* e1 = &mydev;
    Employee* e2 = &myteacher;

    e1->Work();
    e2->Work();
}