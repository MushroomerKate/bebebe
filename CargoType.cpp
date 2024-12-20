#include <iostream>
#include <algorithm>
#include "CargoType.h"

using namespace std;

    CargoType::CargoType(unique_ptr<Cost>&& htc = {}) : howto_count(move(htc)), Tariff_type(0)
    {
    }
    void CargoType::set_strategy(unique_ptr<Cost>&& htc)
    {
        howto_count = move(htc);
    }
    double CargoType::calculate_cost(double mass, int Tariff_type, Company& comp) const
    {
        if (howto_count) {
            double result = howto_count->cost(mass, Tariff_type, comp);
            return (result);
        }
        else {
            //cout << "Context: Strategy isn't set\n";
        }
    }