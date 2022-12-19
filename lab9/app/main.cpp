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

// route.addPoint(RoutePoint(0.0, 0.0, "Peter"));
// route.addPoint(RoutePoint(100.0, 0.0, "Voronezh"));
// route.addPoint(RoutePoint(0.0, 200.0, "Moscow"));
//vehicle[0]->drive(50);
//vehicle[0]->refuel();
//vehicle[0]->drive(29);
//vehicle[0]->printStatus();
//vehicle[0]->drive(150);
//vehicle[0]->drive(100);
//vehicle[1]->drive(90);
//vehicle[1]->drive(20);
//vehicle[1]->printStatus();
return 0;
}
