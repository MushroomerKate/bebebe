#pragma once
#include <iostream>
#include <string>
#include "Tariff.h"
class Company
{
public:
    Tariff* tariffs = new Tariff[5];
    string name;
    static Company& getInstance();
    void add_Tariff(string n, double r, double d);
    void LoadData();
    int cheapest_Tariff();
    void output_tariffs();
    void LoadData_base();
private:
    Company() : name("Company1") { };
    ~Company();
    Company(Company const&);
    Company& operator= (Company const&);
};