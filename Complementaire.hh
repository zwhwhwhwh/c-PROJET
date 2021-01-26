#pragma once
#include<iostream>
#include <cstdlib>
#include <string>
#include "RGB.hh"
#include "HSV.hh"
#include <vector>

/*La couleur complémentaire de la couleur spécifiée */

class Complementaire:public RGB {
public:
Complementaire(const ColorSpace&);
friend std::ostream& operator<<(std::ostream& , const Complementaire &);
};

Complementaire::Complementaire(const ColorSpace& c):RGB(){
	vector<size_t> v=c.toRGB();
	x=255-v[0];
	y=255-v[1];
	z=255-v[2];
}

std::ostream& operator<<(std::ostream& os , const Complementaire& c)
{
        os << c.hexadecimal() << endl;
 
   return os;
}
