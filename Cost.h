#pragma once
#include "Company.h"

class Cost
{
public:
    virtual ~Cost();
    virtual double cost(double mass, int Tariff_type, Company& comp) const = 0;
};