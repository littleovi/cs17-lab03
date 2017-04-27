//
// Created by u211-03 on 27.04.2017.
//
#include<sstream>
#include<cassert>
#include"tempreture.h"
using namespace std;
int main(){
    stringstream in ("17C");
    tempreture t;
    in>> t;
    assert(t.value == 17);
    assert(t.scale == Celcium);

    stringstream im ("-66F");
    im>> t;
    assert(t.value == -66);
    assert(t.scale == Farengheite);

    stringstream is ("28K");
    is>> t;
    assert(t.value == 28);
    assert(t.scale == Kelvin);

    stringstream il("Just enjoy the moment");
    il>> t;
    assert(!il);

    stringstream ip ("C:");
    ip>> t;
    assert(!ip);

    stringstream ir("13milky way");
    ir>> t;
    assert(!ir);

}