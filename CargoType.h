#pragma once
#include "Company.h"
#include "Cost.h"

using namespace std;

class CargoType
{
private:
    unique_ptr<Cost> howto_count;
public:
    int Tariff_type;
    explicit CargoType(unique_ptr<Cost>&& htc);
    void set_strategy(unique_ptr<Cost>&& htc);
    double calculate_cost(double mass, int Tariff_type, Company& comp) const;
};