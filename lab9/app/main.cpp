#include <iostream>
#include "C:\Users\portl\OneDrive\Desktop\Qt\SVP\lr9\Objects\objects.h"
using namespace std;

int main(int argc, char* argv[]) {

Route route;
route.checkArgc(argc);

IVehicle* vehicle[4] = { new Sedan, new Bicycle, new Bus, new Suv };

string place = argv[1];
route.openFile(place);

for (int i = 0; i < 4; i++){
    route.run(vehicle[i]);
    vehicle[i]->printStatus();
}

// route.addPoint(RoutePoint(0.0, 0.0, "Moscow"));
// route.addPoint(RoutePoint(90.0, 0.0, "Peter"));
// route.addPoint(RoutePoint(0.0, 20000.0, "Voronezh"));
//vehicle[0]->drive(50);
//vehicle[0]->refuel();
//vehicle[0]->drive(29);
//vehicle[0]->printStatus();
//vehicle[0]->drive(180);
//vehicle[0]->drive(1000);
//vehicle[1]->drive(100);
//vehicle[1]->drive(10);
//vehicle[1]->printStatus();
return 0;
}
