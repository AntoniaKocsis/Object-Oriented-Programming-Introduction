#include <iostream>
#include <sstream>

using namespace std;
//struct Date {
//    int day, year, month;
//};
//Date generateDate(string date) {
//    string day,month,year;
//    stringstream s1(date);
//    getline(s1, day, '/');
//    getline(s1, month, '/');
//    getline(s1, year);
//    Date d1;
//    d1.day = stoi(day);
//    d1.month = stoi(month);
//    d1.year = stoi(year);
//    return d1;
//}
namespace electricScooter {
    class ElectricScooter {
    private:
        string identifier;
        string model;
        string commissioningDate;
        float mileage;
        string lastLocation;
        string currentCondition;
    public:
        ElectricScooter(string identifier, string model, string commissioningDate, float mileage, string lastLocation,
                        string currentCondition);
        ElectricScooter(string id);

        string getId();

        string getModel();

        string getDate();

        float getMileage() const;

        string getLocation();

        string getCondition();

        void setId(string id);

        void setModel(string model);

        void setDate(string date);

        void setMileage(float mileage);

        void setLocation(string location);

        void setCondition(string condition);


    };
}