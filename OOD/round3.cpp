#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;


class Stations{
    protected:
        string name;
    public: 
        Stations(string myname){
            name = myname;
        }
        string getStation(){
            return name;
        }

};

class Trains{
    protected:
        string trainName;
        string departTime;
    public:
        Trains(string myTrainName, string departure){
            trainName = myTrainName;
            departTime = departure;
        }
        string getTrainName(){
            return trainName;
        }
        string getDepartTime(){
            return departTime;
        }
};

class Coaches: public Trains{
    protected:
        string coachType;
        string coachId;
        int cost;
        int filledSeats;
        int freeSeats;
        int bookedSeats;
    public: 
        Coaches(string type, int cost, int filledSeats, int freeSeats, int bookedSeats, string myTrainName, string departure, string coachid)
                : Trains(myTrainName, departure){
            coachType = type;
            cost = cost;
            filledSeats = filledSeats;
            freeSeats = freeSeats;
            bookedSeats = bookedSeats;
            coachId = coachid;
        };
        string getCoachType(){
            return coachType;
        };
        int getCost(){
            return cost;
        };
        int getFilledSeats(){
            return filledSeats;
        };
        int getFreeSeats(){
            return freeSeats;
        };
        int getBookedSeats(){
            return bookedSeats;
        };
        string getCoachId(){
            return coachId;
        }
        void setCost(){
            // return cost;
            cost = cost;
        };
        void setFilledSeats(){
            // return filledSeats;
            filledSeats++;
        };
        void setFreeSeats(){
            // return freeSeats;
            freeSeats--;
        };
        void setBookedSeats(){
            bookedSeats++;
        }
};

class Seats: public Coaches{
    protected: 
        string from;
        string to;
        string date;
        int costOfSeats = 0;
        int seatNo;
    public:
        Seats(string from,int seatNo, string to, string type, int cost, int filledSeats, int freeSeats, int bookedSeats, string departure, string myTrainName, string coachid)
                : Coaches(type, cost, filledSeats, freeSeats, bookedSeats,myTrainName, departure, coachId){
            from = from;
            to = to;
            date = date;
        }
};
class User{
    string name; 
    string date;
};
class BookingApp{
    private: 
        unordered_map<string, vector<Trains>> myTrains;
        unordered_map<string, vector<Coaches>> myCoaches;
        unordered_map<string, vector<Seats>> mySeats;
        vector<Stations> myStations;
    public: 
        BookingApp(){

            Stations station1("Ernakulam");
            Stations station2("Kottayam");
            Stations station3("Kayamkulam");
            Stations station4("Kollam");
            Stations station5("Trivandrum");
            myStations.push_back(station1);
            myStations.push_back(station2);
            myStations.push_back(station3);
            myStations.push_back(station4);
            myStations.push_back(station5);

            Trains currentTrain("Train 1", "4pm");
            myTrains[__DATE__].push_back(currentTrain);
            
            for(auto elements: myTrains[__DATE__]){
                string trainName = elements.getTrainName();
                string departTime = elements.getTrainName();
                Coaches Coach1("Normal", 10,0,10,0,trainName, departTime,"1");
                Coaches Coach2("Premium", 20,0,5,0,trainName, departTime, "2");
                myCoaches[__DATE__].push_back(Coach1);
                myCoaches[__DATE__].push_back(Coach2);
            }
            cout<<"Initialized"<<endl;
        };
        int getCost(string source, string destination, string type, int bookedSeats){
            int start = 0;
            int end = 0;
            int index = 0;
            int cost = 0;
            for(auto element: myStations){
                if(source == element.getStation()){
                    start = index;
                }
                if(destination == element.getStation()){
                    end = index;
                }
                index++;
            }
            if(type == "Normal"){
                cost = (end - start + 1) * 10;
            }else if(type == "Premium"){
                cost = (end - start + 1) * 20 + bookedSeats * 5;
            }
            
            return cost;

        }
        void bookSeat(string date, string type, string source, string destination){
            int cost = 0;
            int check = 0;
            for(auto elements: myCoaches[date]){
                if(elements.getCoachType() == type){
                    if(elements.getFreeSeats()!=0){
                        cout<<"Tickets Available"<<endl;
                        check = 1;
                        elements.setBookedSeats();
                        elements.setFilledSeats();
                        elements.setFreeSeats();
                        int seatId = mySeats.size() + 1;
                        int mycost = getCost(source, destination, type, elements.getBookedSeats());
                        cout<<mycost<<endl;
                        Seats myCurrentSeat(source, seatId, destination, type, mycost, elements.getFilledSeats(), elements.getFreeSeats(), elements.getBookedSeats(),elements.getDepartTime(), elements.getTrainName(), elements.getCoachId());
                        cout<<"Hello"<<endl;
                        mySeats[__DATE__].push_back(myCurrentSeat);
                        check = 1;
                        break;
                    }else{
                        check = 0;
                    }
                }
            }
            if(check = 0){
                cout<<"Not Available"<<endl;
            }
            if(type == "Normal"){

            }
        }
};



int main(){
    BookingApp myBookingApp;
    myBookingApp.bookSeat(__DATE__, "Normal", "Ernakulam", "Kollam");
    myBookingApp.bookSeat(__DATE__, "Normal", "Ernakulam", "Kollam");
    myBookingApp.bookSeat(__DATE__, "Premium", "Ernakulam", "Kollam");
    return 0;
}