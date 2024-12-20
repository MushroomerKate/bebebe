#pragma once
#include "Company.h"
#include "Cost.h"

class woDiscount : public Cost
{
public:
    double cost(double mass, int Tariff_type, Company& comp) const override;
};