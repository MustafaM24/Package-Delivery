
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "truckDelivery.hpp"


using namespace std;

int main()
{
    
    TruckDelivery delivery;
    delivery.loadTrucks();
    delivery.calculateCost();
    delivery.makeJourney();
    delivery.unloadTrucks();
    return 0;

}
