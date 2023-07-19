#include "Payment.h"

Payment::Payment(const std::string &address) : address_(address)
{
}

Heat::Heat(const std::string &address, double area) : Payment(address), area_(area)
{
}

double Heat::calculate() const
{
    return PAY_HEAT * area_;
}

Water::Water(const std::string &address, long long int numberOfPeople) : Payment(address), numberOfPeople_(numberOfPeople)
{
}

double Water::calculate() const
{
    return static_cast<double>(PAY_WATER * numberOfPeople_);
}

Electricity::Electricity(const std::string &address, double kwHr) : Payment(address), kwHr_(kwHr)
{
}

double Electricity::calculate() const
{
    return PAY_ELECTRICITY * kwHr_;
}
