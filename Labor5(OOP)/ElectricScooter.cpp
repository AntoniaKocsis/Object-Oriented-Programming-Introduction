#include "ElectricScooter.h"

using namespace electricScooter;


ElectricScooter::ElectricScooter(string id, string model, string date, float mileage, string lastLocation,
                                 string condition) {
    if (id.size() != 3)
        throw invalid_argument("");
    this->identifier = id;
    this->model = model;
    this->mileage = mileage;
    this->lastLocation = lastLocation;
    this->currentCondition = condition;
    this->commissioningDate = date;

}
ElectricScooter::ElectricScooter(string id) {
    if (id.size() != 3)
        throw invalid_argument("");
    this->identifier = id;
}
string ElectricScooter::getDate() { return commissioningDate; }

string ElectricScooter::getCondition() { return currentCondition; }

string ElectricScooter::getId() { return identifier; }

string ElectricScooter::getLocation() { return lastLocation; }

float ElectricScooter::getMileage() const { return mileage; }

string ElectricScooter::getModel() { return model; }

void ElectricScooter::setDate(string date) {
    this->commissioningDate = date;
}

void ElectricScooter::setCondition(string condition) {
    this->currentCondition = condition;
}

void ElectricScooter::setModel(string model) {
    this->model = model;
}

void ElectricScooter::setLocation(string location) {
    lastLocation = location;
}

void ElectricScooter::setId(string id) {
    if (id.size() != 3)
        throw invalid_argument(" ");
    identifier = id;
}

void ElectricScooter::setMileage(float mileage) { this->mileage = mileage; }