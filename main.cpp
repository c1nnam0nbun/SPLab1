#include <iostream>

#include "taxi.h"

int main()
{
    Taxi heapTaxi(156151, 5641058, 4874478, 874989, 4891548, 489645, 4895548);
    heapTaxi.calculateEstimatedPrice();
    heapTaxi.setLastInspectionDate(Date(31,11,2018));
    int priceH = heapTaxi.calculateEstimatedPrice();
    if (priceH > -1) {
        std::cout << "Last inspection date: " << heapTaxi.getLastInspectionDate().toString() << '\n';
        std::cout << "Your estimated price: " << priceH << '\n';
    }

    Taxi* stackTaxi = new Taxi(189419684, 1871581, 6568641, 65461, 1798964, 18941, 8416855);
    stackTaxi->setLastInspectionDate(Date(4,12,2010));
    stackTaxi->setMileage(2000);
    stackTaxi->setProductionYear(2010);
    int priceSt = stackTaxi->calculateEstimatedPrice();
    if (priceSt > -1) {
        std::cout << "Last inspection date: " << stackTaxi->getLastInspectionDate().toString() << '\n';
        std::cout << "Your estimated price: " << priceSt << '\n';
    }
    delete stackTaxi;
}
