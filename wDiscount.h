#pragma once
#include "Company.h"
#include "Cost.h"

class wDiscount : public Cost
{
public:
    double cost(double mass, int Tariff_type, Company& comp) const override;
};