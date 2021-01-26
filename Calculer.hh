#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include "color.hh"
#include "RGB.hh"

/* Mélange de deux couleurs */

class Calculer : public RGB{

    public:
    Calculer(const ColorSpace& a,const ColorSpace& b);
    
};

Calculer::Calculer(const ColorSpace& a,const ColorSpace& b):RGB(){
    vector<size_t> v1 = a.toRGB();
    vector<size_t> v2 = b.toRGB();

    x = (v1[0] + v2[0])/2;        //Calculez la moyenne des valeurs RGB de deux couleurs
    y = (v1[1] + v2[1])/2;
    z = (v1[2] + v2[2])/2;
}

