#include "woDiscount.h"

    double woDiscount::cost(double mass, int Tariff_type, Company& comp) const
    {
        double cost;
        cost = mass * comp.tariffs[Tariff_type].rate;
        return (cost);
    }