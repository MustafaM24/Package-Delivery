#include "truck.hpp"
using namespace std;

class TruckDelivery
{
    private:
        Truck trucks[100];
        int numOftrucks;
    public:
        void loadTrucks()
        {
            ifstream file("Drivers.txt");
            string info, truckD;
            int truckNum, truckP, truckM, truckCap, truckIsEmpty= 0;
            int count = 1;
            while (getline(file, info)) 
            {
                if (count%5==1) truckD = info;
                else if (count%5==2) truckP=stoi(info);
                else if (count%5==3) truckM=stoi(info);
                else if (count%5==4) truckIsEmpty=stoi(info);
                else if (count%5==0) truckCap=stoi(info);

                if (count%5==0)  
                {
                    trucks[truckNum].load(truckD, truckP, truckM, truckCap, truckIsEmpty); 
                    truckNum++;
                }
                count++;
            }
            numOftrucks = truckNum;
        }
        void calculateCost()
        {
            for (int i=0; i < numOftrucks; i++)
            {
                float costOfTravel = trucks[i].cost(1);
                float costOfGas = trucks[i].cost(2);
                cout << "Truck " << i+1 << "'s cost Gas: " << costOfGas << endl;
                cout << "Truck " << i+1 << "'s petrol used in the Trip: " << trucks[i].cost() << endl;
                cout << "Truck " << i+1 << "'s total cost of Journey: " << costOfTravel << endl;
                if (costOfTravel > trucks[i].getMoney() || costOfGas > trucks[i].getMoney())
                {
                    trucks[i].set_isDeliveryPossible(false);
                }
                else
                {
                    trucks[i].set_isDeliveryPossible(true);
                }   
                cout << "can make delivery = " << trucks[i].get_isDeliveryPossible() << endl << endl;
            }
        }
        void makeJourney()
        {
            for (int i=0; i < numOftrucks; i++)
            {
                if (trucks[i].get_isDeliveryPossible())
                {
                    int truckCost = trucks[i].getMoney() - trucks[i].cost(2);
                    int truckGas = 50.0 - trucks[i].cost(3); 
                    trucks[i].setMoney(truckCost);
                    trucks[i].setPetrol(truckGas);
                }
            }
        }
        void unloadTrucks()
        {
            ofstream file("Drivers.txt");
            for(int i=0; i < numOftrucks; i++)
            {
                trucks[i].showInfo();
                trucks[i].unload();
                file << trucks[i].getDriver() << endl;
                file << trucks[i].getPetrol() << endl;
                file << trucks[i].getMoney() << endl;
                file << trucks[i].getEmptyMileage() << endl;
                file << trucks[i].getFullMileage() << endl;
            }
            file.close();
        }
};