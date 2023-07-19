#include <string>

#define PAY_HEAT 50
#define PAY_WATER 200
#define PAY_ELECTRICITY 5

class Payment
{
public:
    std::string address_;

    explicit Payment(const std::string &address);

    virtual double calculate() const = 0;
};

class Heat : public Payment
{
private:
    double area_;

public:
    explicit Heat(const std::string &address, double area);

    double calculate() const override;
};

class Water : public Payment
{
private:
    long long numberOfPeople_;

public:
    explicit Water(const std::string &address, long long int numberOfPeople);

    double calculate() const override;
};

class Electricity : public Payment
{
private:
    double kwHr_;

public:
    explicit Electricity(const std::string &address, double kwHr);

    double calculate() const override;
};