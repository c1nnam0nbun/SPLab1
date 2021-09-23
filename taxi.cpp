#include "taxi.h"

#include <iostream>
#include <sstream>
#include <limits.h>

Taxi::Taxi(unsigned int carCode,unsigned int  bodyCode, unsigned int engineCode, unsigned int brandCode, unsigned int registerCode, unsigned int driverCode, unsigned int mechanicCode)
    :m_CarCode(carCode), m_BodyCode(bodyCode), m_EngineCode(engineCode), m_BrandCode(brandCode),
      m_RegisterCode(registerCode), m_DriverCode(driverCode), m_MechanicCode(mechanicCode), m_ProductionYear(1900), m_Mileage(UINT_MAX), m_LastInspectionDate(1,1,1960)
{
    std::cout << "New entry created: " << getFullCode() << '\n';
}

unsigned int Taxi::getRegisterCode() const { return m_RegisterCode; }
unsigned int Taxi::getCarCode() const { return m_CarCode; }
inline unsigned int Taxi::getBrandCode() const { return m_BrandCode; }

unsigned int Taxi::getBodyCode() const { return m_BodyCode; }
inline void Taxi::setBodyCode(unsigned int code) { m_BodyCode = code; }

unsigned int Taxi::getEngineCode() const { return m_EngineCode; }
inline void Taxi::setEngineCode(unsigned int code) { m_EngineCode = code; }

unsigned int Taxi::getDriverCode() const { return m_DriverCode; }
void Taxi::setDriverCode(unsigned int code) { m_DriverCode = code; }

unsigned int Taxi::getMechanicCode() const { return m_MechanicCode; }
void Taxi::setMechanicCode(unsigned int code) { m_MechanicCode = code; }

unsigned short Taxi::getProductionYear() const { return m_ProductionYear; }
void Taxi::setProductionYear(unsigned short year) { m_ProductionYear = year; }

unsigned int Taxi::getMileage() const { return m_Mileage; }
void Taxi::setMileage(unsigned int mileage) { m_Mileage = mileage; }

Date Taxi::getLastInspectionDate() const { return m_LastInspectionDate; }
void Taxi::setLastInspectionDate(const Date& date) { m_LastInspectionDate = date; }

std::string Taxi::getFullCode()
{
    std::stringstream ss;
    ss << "\n\tCar code: " << m_CarCode << "\n\tBody code: " << m_BodyCode << "\n\tEngine code: " << m_EngineCode << "\n\tBrand code: " << m_BrandCode << "\n\tRegister code: " << m_RegisterCode << "\n\tDriver code: " << m_DriverCode << "\n\tMechanic code: " << m_MechanicCode;
    return ss.str();
}

//Since taxi price depends on route distance, we can only approximate
//it based on car's state
int Taxi::calculateEstimatedPrice()
{
    if (m_LastInspectionDate < Date(11, 8, 2005))
    {
        std::cout << "Inspection needed. Cannot do orders." << std::endl;
        return -1;
    }
    int basePrice = 100;
    if (m_ProductionYear > 2000) basePrice += 30;
    if (m_Mileage < 3000) basePrice += 50;
    return basePrice;
}
