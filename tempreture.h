//
// Created by u211-03 on 27.04.2017.
//

#pragma once
#include <iostream>

enum Scale{
    Kelvin = 'K', Celcium = 'C', Farengheite = 'F'
};
struct tempreture{
    Scale scale;
    double value;
};
tempreture  convert(const tempreture& from, Scale scale);
std::istream& operator >> (std::istream& in, tempreture& t) ;
bool operator < (tempreture& lhs,tempreture& rhs);


