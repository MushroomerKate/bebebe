#include <string>
#include "Tariff.h"

using namespace std;

    Tariff::Tariff() : name(""), rate(0), discount(0)
    { }
    Tariff::~Tariff() = default;
    void Tariff::set_name(string n) {
        name = n;
    }
    void Tariff::set_rate(double r) {
        rate = r;
    }
    void Tariff::set_discount(double d) {
        rate = d;
    }