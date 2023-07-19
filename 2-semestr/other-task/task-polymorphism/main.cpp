#include <iostream>
#include "src/Payment.h"

int main()
{
    Payment* mas[7];

    Heat heatOne("heatOne", 34);
    Heat heatTwo("heatTwo", 36);

    Water waterOne("waterOne", 5);
    Water waterTwo("waterTwo", 6);
    Water waterThree("waterThree", 4);

    Electricity electricityOne("electricityOne", 40);
    Electricity electricityTwo("electricityTwo", 42);

    mas[0] = &heatOne;
    mas[1] = &heatTwo;
    mas[2] = &waterOne;
    mas[3] = &waterTwo;
    mas[4] = &waterThree;
    mas[5] = &electricityOne;
    mas[6] = &electricityTwo;

    double sum = 0;
    for(auto & iter : mas)
    {
        std::cout << iter->address_ << " : " << iter->calculate() << std::endl;
        sum += iter->calculate();
    }
    std::cout << "summa : " << sum << std::endl;

    return 0;
}