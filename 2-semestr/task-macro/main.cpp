#include <iostream>
#include <map>
#include <vector>


#define ASSERT(X) if(!(X)){ std::cout << "ASSERT ERROR (" << #X << ") line: " << __LINE__ << " file: " << __FILE__ << std::endl;exit(-1);}

//-----------------------------------------------------------------------------------------------

#define CHECK_STR(P) if(m.count(#P)) c.P = m[#P];
#define CHECK_DOUBLE(P) if(m.count(#P)) c.P = std::stod(m[#P]);
#define CHECK_INT(P) if(m.count(#P)) c.P = std::stoi(m[#P]);
#define CHECK_DOUBLE(P) if(m.count(#P)) c.P = std::stod(m[#P]);
#define CHECK_ULL(P) if(m.count(#P)) c.P = std::stoull(m[#P]);

class Car
{
public:
    std::string producer;
    std::string model;
    std::string color;
    double power{};
    int year{};
    unsigned long long price{};
};

void UpdateCar(Car& c, std::map<std::string, std::string>& m)
{
    CHECK_STR(producer)
    CHECK_STR(model)
    CHECK_STR(color)
    CHECK_DOUBLE(power)
    CHECK_INT(year)
    CHECK_ULL(price)
}

//-----------------------------------------------------------------------------------------------

#define CONCAT_(prefix, suffix) prefix##suffix
#define CONCAT(prefix, suffix) CONCAT_(prefix, suffix)
#define UNIQ_ID CONCAT(UNIQID##_, __LINE__)

//-----------------------------------------------------------------------------------------------

int main()
{
    int x = 4;
    ASSERT(x == 5 || x == 4);
    //ASSERT(!x);
    //ASSERT(x == 3);

    //---------------------------------------------

    Car c;
    c.producer = "VAZ";
    c.model = "Lada_Vesta";
    c.power = 91.5;
    c.color = "white";
    c.year = 2015;
    c.price = 900000;
    std::map<std::string, std::string> m = {
            {"model", "Lada_Granta"},
            {"power", "80.5"},
            {"year", "2021"},
            {"price", "675000"} };

    UpdateCar(c, m);

    ASSERT(c.producer == "VAZ");
    ASSERT(c.model == "Lada_Granta");
    ASSERT(c.power == 80.5);
    ASSERT(c.color == "white");
    ASSERT(c.year == 2021);
    ASSERT(c.price == 675000);

    //---------------------------------------------

    int UNIQ_ID = 0;
    double UNIQ_ID = 12.7;
    std::string UNIQ_ID = "hello";

    //---------------------------------------------

    return 0;
}