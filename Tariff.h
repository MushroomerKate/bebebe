#pragma once
#include <string>

using namespace std;

class Tariff
{
public:
    string name;
    double rate;
    double discount;
    Tariff();
    ~Tariff();
    void set_name(string n);
    void set_rate(double r);
    void set_discount(double d);
};