#include "objects.h"

Objects::Objects()
{
}

Bicycle::~Bicycle()
{

}

bool Bicycle::drive(float kilometers)
{
    mileage += kilometers;
    return true;
}

void Bicycle::refuel()
{

}

void Bicycle::printStatus()
{
    cout << mileage << endl;
}

float Bicycle::get_mileage()
{
    return this->mileage;
}

Vehicle::~Vehicle() {}

bool Vehicle::drive(float kilometers)
{
    float calculation = ((kilometers / 100.0) * fuel_flow);
    float maxCapacity = capacity / ((kilometers / 100.0) * fuel_flow);
    float remains = kilometers;
    if (calculation <= fuel) {
        mileage += kilometers;
        fuel -= calculation;
        cout << endl;
        cout << "Distance was drove" << endl;
        cout << endl;
        return true;
    }
    else {
        while(remains > maxCapacity){
            cout << "Not petrol" << endl;
            refuel();
            cout << "refuel" << endl;
            remains -= maxCapacity;
            mileage += maxCapacity;
            fuel -= capacity;
        }
        if (remains > 0.0) {
            refuel();
            mileage += remains;
            fuel -= calculation;
        }
    }
}

void Vehicle::refuel()
{
    fuel = capacity;
}

void Vehicle::printStatus()
{
    cout << endl;
    cout << mileage << endl;
    cout << fuel << endl;
    cout << endl;
}

Sedan::Sedan()
{
    this->capacity = 50;
    this->fuel_flow = 8.5;
}

Sedan::~Sedan()
{

}

Sedan::Sedan(double a, double b)
{
    this->capacity = a;
    this->fuel_flow = b;
}

double Sedan::getFuelLevel()
{
    return this->fuel;
}

double Sedan::getMilage()
{
    return this->mileage;
}

Bus::Bus()
{
    cin >> this->capacity;
    cin >> this->fuel_flow;
}

Bus::~Bus()
{

}

Suv::Suv()
{
    cin >> this->capacity;
    cin >> this->fuel_flow;
}

Suv::~Suv()
{

}

RoutePoint::RoutePoint(float xKm, float yKm, string name)
{
    this->xKm = xKm;
    this->yKm = yKm;
    this->name = name;
}

Route::Route()
{

}

Route::~Route()
{

}

void Route::addPoint(const RoutePoint &point)
{
    points.push_back(point);
}

void Route::run(IVehicle *vehicle)
{
    if (points.size() > 1) {
        float distance = 0.0;
        for (int i = 0; i < points.size() - 1; i++) {
            distance = sqrt( pow( (points[i + 1].xKm - points[i].xKm), 2) + pow((points[i + 1].yKm - points[i].yKm), 2));
            vehicle->drive(distance);
        }
    }
    else {
        cout << "Error" << endl;
    }
}

void Route::checkArgc(int argc)
{
    if (argc < 2) {
        cout << "Error of parameters" << endl;
        exit(1);
    }
}

void Route::openFile(string place)
{
    string path = "/C/Users/portl/OneDrive/Desktop/Qt/SVP/build-Lab_9-Desktop_Qt_5_14_2_MinGW_32_bit-Debug/app/debug/" + place;

    ifstream file(path);

    if (file.is_open()){
        cout << endl;
        cout << "File open" << endl;
        cout << endl;

        string txt;

        float x, y;

        while (!file.eof()){
            int count = 1;
            switch (count){
            case 1:
                file >> txt;
                x = atof( (txt).c_str() );
                count++;

            case 2:
                file >> txt;
                y = atof( (txt).c_str() );
                count++;

            case 3:
                file >> txt;
                addPoint(RoutePoint(x, y, txt));
                count = 1;

            }

        }

    }
    else{
        cout << "File not open" << endl;
    }
}

