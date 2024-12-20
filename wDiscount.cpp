#include "wDiscount.h"

    double wDiscount::cost(double mass, int Tariff_type, Company& comp) const
    {
        double cost;
        cost = mass * comp.tariffs[Tariff_type].rate * (1 - comp.tariffs[Tariff_type].discount);
        return (cost);
    }