#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Vehicle
{
protected:
    string registrationNo;
    string ownerName;
    int yearOfManufacture;
    double kmDriven;

public:

    Vehicle(const string& reg, const string& owner,
            int year, double km)
    {
        registrationNo = reg;
        ownerName = owner;
        yearOfManufacture = year;
        kmDriven = km;

        cout << "[Vehicle Constructor] "
             << registrationNo << " : "
             << ownerName << endl;
    }

    virtual double fuelCost(double kmToTravel) const = 0;

    virtual void describe() const
    {
        cout << "Registration : "
             << registrationNo << endl;

        cout << "Owner : "
             << ownerName << endl;

        cout << "Year : "
             << yearOfManufacture << endl;

        cout << "KM Driven : "
             << kmDriven << endl;
    }

    virtual string vehicleType() const = 0;

    virtual ~Vehicle()
    {
        cout << "[Vehicle Destructor] "
             << registrationNo << endl;
    }

    double getKmDriven() const
    {
        return kmDriven;
    }

    string getRegNo() const
    {
        return registrationNo;
    }

    string getOwnerName() const
    {
        return ownerName;
    }
};

class Car : public Vehicle
{
private:
    string fuelType;
    double mileageKmpl;

public:

    Car(const string& reg, const string& owner,
        int year, double km,
        const string& fuel, double mileage)
        : Vehicle(reg, owner, year, km)
    {
        fuelType = fuel;
        mileageKmpl = mileage;

        cout << "[Car Constructor] "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override
    {
        double fuelPrice;

        if (fuelType == "Petrol")
        {
            fuelPrice = 106.00;
        }
        else
        {
            fuelPrice = 93.00;
        }

        return (kmToTravel / mileageKmpl) * fuelPrice;
    }

    string vehicleType() const override
    {
        return "Car";
    }

    void describe() const override
    {
        Vehicle::describe();

        cout << "Fuel Type : "
             << fuelType << endl;

        cout << "Mileage : "
             << mileageKmpl << endl;
    }
};

class Truck : public Vehicle
{
protected:
    double payloadCapacityTons;
    double fuelEfficiencyKmpl;

public:

    Truck(const string& reg, const string& owner,
          int year, double km,
          double payload, double efficiency)
        : Vehicle(reg, owner, year, km)
    {
        payloadCapacityTons = payload;
        fuelEfficiencyKmpl = efficiency;

        cout << "[Truck Constructor] "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override
    {
        double efficiency =
            fuelEfficiencyKmpl *
            (1 - 0.05 * payloadCapacityTons);

        return (kmToTravel / efficiency) * 93.00;
    }

    string vehicleType() const override
    {
        return "Truck";
    }

    void describe() const override
    {
        Vehicle::describe();

        cout << "Payload : "
             << payloadCapacityTons << " tons"
             << endl;

        cout << "Efficiency : "
             << fuelEfficiencyKmpl << endl;
    }

    ~Truck()
    {
        cout << "[Truck Destructor] "
             << registrationNo << endl;
    }
};

class ElectricTruck : public Truck
{
private:
    double batteryCapacityKWh;
    double rangePerChargeKm;
    double batteryPercent;

public:

    ElectricTruck(const string& reg, const string& owner,
                  int year, double km,
                  double payload, double efficiency,
                  double battery, double range,
                  double batteryLevel = 85)
        : Truck(reg, owner, year, km,
                payload, efficiency)
    {
        batteryCapacityKWh = battery;
        rangePerChargeKm = range;
        batteryPercent = batteryLevel;

        cout << "[ElectricTruck Constructor] "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override
    {
        return (kmToTravel / rangePerChargeKm)
               * batteryCapacityKWh * 9.50;
    }

    string vehicleType() const override
    {
        return "Electric Truck";
    }

    void describe() const override
    {
        Vehicle::describe();

        cout << "Battery : "
             << batteryCapacityKWh << " kWh"
             << endl;

        cout << "Range : "
             << rangePerChargeKm << " km"
             << endl;
    }

    double getBatteryPercent() const
    {
        return batteryPercent;
    }

    ~ElectricTruck()
    {
        cout << "[ElectricTruck Destructor] "
             << registrationNo << endl;
    }
};

class Van : public Vehicle
{
private:
    int seatingCapacity;
    double mileageKmpl;

public:

    Van(const string& reg, const string& owner,
        int year, double km,
        int seats, double mileage)
        : Vehicle(reg, owner, year, km)
    {
        seatingCapacity = seats;
        mileageKmpl = mileage;

        cout << "[Van Constructor] "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override
    {
        return (kmToTravel / mileageKmpl) * 106.00;
    }

    string vehicleType() const override
    {
        return "Van";
    }

    void describe() const override
    {
        Vehicle::describe();

        cout << "Seats : "
             << seatingCapacity << endl;

        cout << "Mileage : "
             << mileageKmpl << endl;
    }

    ~Van()
    {
        cout << "[Van Destructor] "
             << registrationNo << endl;
    }
};

void printFleetReport(const vector<Vehicle*>& fleet,
                      double tripKm)
{
    cout << endl;
    cout << "===== FLEET REPORT =====" << endl;

    cout << left
         << setw(15) << "Registration"
         << setw(18) << "Type"
         << setw(20) << "Owner"
         << "KM Driven" << endl;

    for (Vehicle* v : fleet)
    {
        cout << left
             << setw(15) << v->getRegNo()
             << setw(18) << v->vehicleType()
             << setw(20) << v->getOwnerName()
             << v->getKmDriven()
             << endl;
    }

    cout << endl;
    cout << "===== FUEL / CHARGE COST ====="
         << endl;

    double lowestCost = 999999999;
    Vehicle* bestVehicle = nullptr;

    for (Vehicle* v : fleet)
    {
        double cost = v->fuelCost(tripKm);

        cout << v->getRegNo()
             << " (" << v->vehicleType()
             << ") : Rs. "
             << fixed << setprecision(2)
             << cost;

        ElectricTruck* electric =
            dynamic_cast<ElectricTruck*>(v);

        if (electric != nullptr)
        {
            cout << " [Battery: "
                 << electric->getBatteryPercent()
                 << "% charged]";
        }

        cout << endl;

        if (cost < lowestCost)
        {
            lowestCost = cost;
            bestVehicle = v;
        }
    }

    cout << endl;

    cout << "Most Efficient Vehicle: "
         << bestVehicle->getRegNo()
         << " (" << bestVehicle->vehicleType()
         << ") - Rs. "
         << lowestCost
         << endl;
}

int main()
{
    cout << "===== CONSTRUCTOR ORDER ====="
         << endl;

    ElectricTruck test(
        "V-ET001",
        "Green Logistics",
        2024,
        89000,
        5,
        4,
        85,
        300
    );

    cout << endl;

    vector<Vehicle*> fleet;

    fleet.push_back(
        new Car("KA01AA001",
                "Ramesh Kumar",
                2020,
                45200,
                "Petrol",
                18)
    );

    fleet.push_back(
        new Truck("MH04BB002",
                  "Shyam Logistics",
                  2019,
                  123500,
                  3,
                  5)
    );

    fleet.push_back(
        new ElectricTruck("GJ07CC003",
                          "Green Fleet Co",
                          2023,
                          89000,
                          2,
                          4,
                          85,
                          300,
                          85)
    );

    fleet.push_back(
        new Van("MH12DD004",
                "City Transport",
                2021,
                65000,
                8,
                14)
    );

    fleet.push_back(
        new Car("MH14EE005",
                "Amit Patil",
                2022,
                30000,
                "Diesel",
                20)
    );

    printFleetReport(fleet, 200);

    for (Vehicle* v : fleet)
    {
        delete v;
    }

    return 0;
}