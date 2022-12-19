#ifndef OBJECTS_H
#define OBJECTS_H
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

class Objects
{
public:
    Objects();
};

class IVehicle {
public:
    virtual bool drive(float kilometers) = 0;
    virtual void refuel() = 0;
    virtual void printStatus() = 0;
};

class Bicycle : public IVehicle {
protected:
    float mileage = 0;
public:
    ~Bicycle();

    bool drive(float kilometers);

    void refuel();

    void printStatus();

    float get_mileage();
};

class Vehicle : public IVehicle {//class AbstractCar

protected:
    float mileage = 0.0;
    float fuel = 0.0;

    float capacity;
    float fuel_flow;
public:
    ~Vehicle();

    bool drive(float kilometers);

    void refuel();

    void printStatus();


};

class Sedan : public Vehicle {

public:
    Sedan();
    ~Sedan();
    Sedan(double a, double b);
    double getFuelLevel();

    double getMilage();
};

class Bus : public Vehicle {

public:
    Bus();
    ~Bus();
};

class Suv : public Vehicle {

public:
    Suv();
    ~Suv();
};

struct RoutePoint {
    float xKm;
    float yKm;
    string name;

    RoutePoint(float xKm, float yKm, string name);
};

class Route {
private:
    vector<RoutePoint>points;
public:
    Route();
    ~Route();

    void addPoint(const RoutePoint& point);

    void run(IVehicle* vehicle);

    void checkArgc(int argc);

    void openFile(string place);

};




#endif // OBJECTS_H
