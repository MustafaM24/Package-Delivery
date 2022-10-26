#include "box.hpp"
#include <string>
using namespace std;
class Truck
{
private:
    string driver;
    int petrol;
    int money;
    int fullMileage;
    int emptyMileage;
    BOX box[10];
    bool isDeliveryPossible;

public:
    void load(string truckD, int truckP, int truckM, int truckCap, int truckIsEmpty)
    {
        driver = truckD;
        petrol = truckP;
        money = truckM;
        fullMileage = truckCap;
        emptyMileage = truckIsEmpty;
        for (int i = 0; i < 10; i++) 
        {
            box[i].height = 5 + (rand() % (30 - 5 + 1)); 
            box[i].length = 5 + (rand() % (30 - 5 + 1)); 
            box[i].width = 5 + (rand() % (30 - 5 + 1)); 
        }
        for (int i = 0; i < 10; i++) 
        {
            cout << "BOX" << i + 1 << endl;
            cout << "  Height: " << box[i].height;
            cout << "  Length: " << box[i].length;
            cout << "  Width: " << box[i].width << endl;
        }
        cout << "\n\n";
    }
    string showInfo()
    {
        string str;
        cout << "Driver: " << driver;
        cout << endl
            << "Petrol: " << petrol << endl;
        cout << "Money: " << money << endl;
        cout << "Full mileage: " << fullMileage << endl;
        cout << "Empty mileage: " << emptyMileage << endl
            << endl;
        return str;
    }
    float cost(int x = 0)
    {
        float gasUsed, costOfJourney, TankFullCost;
        gasUsed = 60.0 / fullMileage;  
        gasUsed += 60.0 / emptyMileage;
        if (gasUsed > 50.0)  
        {                           
            isDeliveryPossible = false; 
        }                        
        TankFullCost = (50.0 - petrol) * 2.73;
        if ((gasUsed - petrol) >= 0)
        {
            costOfJourney = (gasUsed - petrol) * 2.73;
        }
        else
        {
            costOfJourney = 0.0; 
        }
        if (x == 1)
            return costOfJourney;
        if (x == 2)
            return TankFullCost;
        else
            ;
        return gasUsed;
    }
    void unload()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << "BOX" << i + 1 << endl;
            cout << "  Height: " << box[i].height;
            cout << "  Length: " << box[i].length;
            cout << "  Width: " << box[i].width << endl;
            cout << "  Volume: " << box[i].V() << endl;
        }
    }
    bool get_isDeliveryPossible()
    {
        return isDeliveryPossible;
    }
    int getMoney()
    {
        return money;
    }
    int getPetrol()
    {
        return petrol;
    }
    string getDriver()
    {
        return driver;
    }
    int getFullMileage()
    {
        return fullMileage;
    }
    int getEmptyMileage()
    {
        return emptyMileage;
    }


    void set_isDeliveryPossible(bool flag)
    {
        isDeliveryPossible = flag;
    }
    void setMoney(int m)
    {
        money = m;
    }
    void setPetrol(int p)
    {
        petrol = p;
    }
};