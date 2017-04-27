//
// Created by u211-03 on 27.04.2017.
//
#include "tempreture.h"

using namespace std;

istream& operator >> (istream& in, tempreture& t) {
    in >> t.value;
    if (!in) {
        in.setstate(ios_base::failbit);
        return in;
    }

    char symbol;
    in >> symbol;

    switch(symbol){
    case 'K':
        t.scale=Kelvin;
        break;
    case 'C':
        t.scale=Celcium;
        break;
    case 'F':
        t.scale=Farengheite;
        break;
    }
    tempreture T;
    T = convert(t, Kelvin);
    if (T.value < 0) {
        in.setstate(ios_base::failbit);
        return in;
    }
    return in;
}

tempreture  convert(const tempreture& from, Scale scale){
    double K;
    switch(from.scale){
    case Kelvin:
        K =  from.value;
        break;
    case Celcium:
        K =  from.value+273,15;
        break;
    case Farengheite:
        K = (from.value+459,67)/1.8;
        break;
    }
    tempreture result;
    result.scale = scale;
    switch(scale){
    case Kelvin:
        result.value = Kelvin;
        break;
    case Celcium:
        result.value = Kelvin-273,15;
        break;
    case Farengheite:
        result.value = (Kelvin*1,8)-459,67;
        break;
    }
    return result;
    //switch по шкале температуры  from,
    // рассчитать K
    //switch о шкале to
    //рассчитать значение результата
}

    bool operator < (tempreture& lhs,tempreture& rhs) {
        tempreture t ;
        t = convert(lhs, rhs.scale);
        return t.value < rhs.value ;

    }
