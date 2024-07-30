#include <iostream>
#include <cmath>
#include <string>
using namespace std;
// int main(){
//     int tempC;
//     cout<<"Enter temperature in Celcius: ";
//     cin>>tempC;
//     double tempF = (tempC * 1.8) + 32;
//     cout<<"Temperature in Farenheit: "<<tempF;
//     return 0;
// }

// int main(){
//     double rfloor = floor(1.2);
//     double rceil = ceil(1.2);
//     double rpow = pow(3,2);
//     cout<<rfloor<<endl<<rceil<<endl<<rpow<<endl;
// }
class Student{
    private: 
        string campusresident;
    public:
        string name;
        string major;
        float gpa;
        bool honors;
        Student(){
            name = "No Name";
            major = "No Major";
            gpa = 0;
        }
        void PassInputs(int i){
            cout<<"Enter name, major and gpa separated by space for Student"<<i<<": ";
            cin>>name>>major>>gpa;
            honors = hasHonors();
            setResidency();
            cout<<endl;
        }
        bool hasHonors(){
            if(gpa>=8.5){
                return true;
            }
            return false;
        }
        void setResidency(){
            cout<<"Enter type of Residency from the options: 'Campus' or 'Day_Scholar' or 'Paying_Guest': ";
            string residency;
            cin>>residency;
            // cout<<residency;
            if (residency == "Campus" || residency == "Day_Scholar" || residency == "Paying_Guest"){
                campusresident = residency;
                cout<<"Residency is set!!"<<endl;
            } else{
                cout<<"Invalid option!!, try again!"<<endl;
            }
        }
        string getResidency(){
            return campusresident;
        }

};
int main(){
    cout<<"Enter number of student objects you want to create: ";
    int n;
    cin>>n;
    Student arrayOfClasses[n];
    for(int i=0;i<n;i++){
        arrayOfClasses[i].PassInputs(i);
    }
    for(int i=0;i<n;i++){
        cout<<arrayOfClasses[i].name<<endl<<arrayOfClasses[i].major<<endl<<arrayOfClasses[i].gpa<<endl<<arrayOfClasses[i].honors<<endl;
        cout<<arrayOfClasses[i].getResidency()<<endl;
        cout<<endl;
    }
}